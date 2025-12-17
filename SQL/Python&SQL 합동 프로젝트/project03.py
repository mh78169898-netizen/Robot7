import sqlite3
import re
import os
print(f"DEBUG: 현재 작업 디렉토리: {os.getcwd()}")
print(f"DEBUG: /var/log/syslog 존재 여부: {os.path.exists('/var/log/syslog')}")
from datetime import datetime

class SyslogAnalyzer:
    def __init__(self, db_path='syslog_analysis.db'):
        self.conn = sqlite3.connect(db_path)
        self.cursor = self.conn.cursor()
        self._init_db()  # 오타 수정

    def _init_db(self):
        """데이터베이스 및 테이블 초기화"""
        self.cursor.execute('DROP TABLE IF EXISTS system_logs') # 공백 추가
        self.cursor.execute("""
            CREATE TABLE system_logs (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                ts DATETIME,
                host TEXT,
                process TEXT,
                level TEXT,
                message TEXT
            )
        """)
        self.conn.commit()
    
    def parse_and_insert(self, log_lines):
        """로그 한 줄씩 파싱하여 DB에 삽입"""
        # P 대문자로 수정
        regex = r"^(?P<ts>\S+)\s+(?P<host>\S+)\s+(?P<proc>[^:\s]+)(?:\[\d+\])?:\s+(?P<msg>.*)$"

        parsed_data = []
        for line in log_lines:
            match = re.search(regex, line.strip())
            if match:
                d = match.groupdict()
                msg_upper = d['msg'].upper()
                level = "INFO"
                if any(k in msg_upper for k in ["ERROR", "FAILED", "CRITICAL"]): level = "ERROR"
                elif any(k in msg_upper for k in ["WARN", "THROTTLING", "DOWN"]): level = "WARN" # 오타 수정

                parsed_data.append((d['ts'], d['host'], d['proc'], level, d['msg']))

        if parsed_data:
            self.cursor.executemany(
                "INSERT INTO system_logs (ts, host, process, level, message) VALUES (?, ?, ?, ?, ?)",
                parsed_data
            )
            self.conn.commit()

    def generate_report(self, target_date_str):
        """요청하신 형식의 보고서 생성 및 출력"""
        print(f"\n시스템 이벤트 타임라인 (syslog)")
        print("=" * 60)

        self.cursor.execute("""
            SELECT strftime('%H:%M', ts) as time, level, process, message
            FROM system_logs
            WHERE ts LIKE ?
            ORDER BY ts DESC
            LIMIT 10
            """, (f'{target_date_str}%',))
        
        rows = self.cursor.fetchall()
        for row in reversed(rows):
            time, level, proc, msg = row
            print(f"{time}  [{level:<5}]  {proc:<15} - {msg}")

        print("\n요약 분석")

        self.cursor.execute("""
            SELECT strftime('%H:%M', ts), message FROM system_logs
            WHERE level IN ('WARN', 'ERROR') ORDER BY ts ASC LIMIT 1
            """)
        first_issue = self.cursor.fetchone()

        # sursor -> cursor 수정
        self.cursor.execute("SELECT message FROM system_logs WHERE message LIKE '%link down%' OR message LIKE '%Failed%' OR message LIKE '%restarted%'")
        events = [r[0] for r in self.cursor.fetchall()]

        print(f"- 첫 이상 징후 : {first_issue[1] if first_issue else '없음'}")
        # 연쇄 이벤트 출력 로직 보정
        chain_items = dict.fromkeys(re.findall(r'eth0|camera|docker', ' '.join(events)))
        print(f"- 연쇄 이벤트  : {' -> '.join(chain_items) if chain_items else '없음'}")

        reason = "정상"
        if any("throttling" in e.lower() for e in events) or first_issue: # throttling 오타 수정
            reason = "시스템 부하 또는 전원 불안정"

        print(f"- 추정 원인    : {reason}")
        print("=" * 60)

if __name__ == "__main__":
    analyzer = SyslogAnalyzer()
    log_file_path = '/var/log/syslog' # 테스트 시 실제 파일명에 맞게 수정 (예: ./syslog)
    
    if os.path.exists(log_file_path):
        with open(log_file_path, 'r', encoding='utf-8') as f:
            actual_logs = f.readlines()
        
        analyzer.parse_and_insert(actual_logs)
        # 로그 데이터에 맞는 날짜로 테스트 (예: 2025-12-17)
        analyzer.generate_report("2025-12-17")
    else:
        print(f"파일을 찾을 수 없습니다: {log_file_path}")
