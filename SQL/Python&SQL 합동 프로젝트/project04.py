import sqlite3
import re
import os

class AuthLogger:
    def __init__(self, db_path='auth_analysis.db'):
        self.conn = sqlite3.connect(db_path)
        self.cursor = self.conn.cursor()
        self._init_db()

    def _init_db(self):
        """인증 로그 분석용 테이블 생성"""
        self.cursor.execute("DROP TABLE IF EXISTS auth_logs")
        self.cursor.execute("""
            CREATE TABLE auth_logs(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                ts TEXT,
                ip TEXT,
                status TEXT,
                message TEXT
            )
        """)
        self.conn.commit()
    
    def parse_auth_log(self, file_path): # 오타 수정
        """auth.log 파싱 및 데이터 분류"""
        total_lines = 0
        parsed_count = 0

        if not os.path.exists(file_path):
            print(f"파일을 찾을 수 없습니다: {file_path}")
            return 0, 0
        
        # ignore 오타 수정
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines() # s 추가 (전체 읽기)
            total_lines = len(lines)

            insert_data = []
            for line in lines:
                status = 'OTHER'
                ip = None

                if "Accepted password" in line or "session opened" in line:
                    status = "SUCCESS"
                elif "Failed password" in line or "authentication failure" in line:
                    status = "FAIL"

                ip_match = re.search(r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})', line)
                if ip_match:
                    ip = ip_match.group(1)

                if len(line) > 15:
                    parsed_count += 1
                    insert_data.append((line[:15], ip, status, line[16:].strip()))

            if insert_data:
                self.cursor.executemany(
                    "INSERT INTO auth_logs(ts, ip, status, message) VALUES (?, ?, ?, ?)",
                    insert_data
                )
                self.conn.commit()

        return total_lines, parsed_count
    
    def print_summary(self, total, parsed):
        """요약 보고서 출력"""
        self.cursor.execute("SELECT COUNT(*) FROM auth_logs WHERE status = 'SUCCESS'")
        success_cnt = self.cursor.fetchone()[0]

        self.cursor.execute("SELECT COUNT(*) FROM auth_logs WHERE status = 'FAIL'")
        fail_cnt = self.cursor.fetchone()[0]

        other_cnt = parsed - (success_cnt + fail_cnt)

        print("\n" + "="*45)
        print(" Linux 인증 로그 요약 (auth.log)")
        print("="*45)
        print(f"총 로그 수      : {total:,}")
        print(f"인식 성공        : {parsed:,}")
        print(f"파싱 실패        : {total - parsed:,}")
        print("-" * 45)
        print(f"인증 성공        : {success_cnt:,}")
        print(f"인증 실패        : {fail_cnt:,}")
        print(f"기타             : {other_cnt:,}")
        print("-" * 45)

        print("인증 실패 상위 IP")
        self.cursor.execute('''
            SELECT ip, COUNT(*) as cnt 
            FROM auth_logs 
            WHERE status='FAIL' AND ip IS NOT NULL 
            GROUP BY ip 
            ORDER BY cnt DESC 
            LIMIT 3
        ''')
        top_ips = self.cursor.fetchall()

        if not top_ips:
            print("탐지된 실패 ip가 없습니다.")
        for i, (ip, count) in enumerate(top_ips, 1):
            print(f"{i}) {ip:<15}: {count}회")
        print("="*45)

# --- 실행부: 여기서부터는 줄 맨 앞에 공백이 없어야 합니다! ---
if __name__ == "__main__":
    LOG_PATH = '/var/log/auth.log'
    analyzer = AuthLogger()
    total, parsed = analyzer.parse_auth_log(LOG_PATH)

    if total > 0:
        analyzer.print_summary(total, parsed)
    else:
        print("분석할 데이터가 없습니다. (sudo 권한을 확인하세요)")
