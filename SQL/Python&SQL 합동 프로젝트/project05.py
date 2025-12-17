import json
import time
import random
import sqlite3
import os
from datetime import datetime

class IoT_Simulator:
    def __init__(self, log_filename = "sensor_logs.json", db_filename = "sensor_data.db"):
        self.log_filename = log_filename
        self.db_filename = db_filename
        self.current_temp = 22.0
        self.current_humi = 50.0

        self.init_db()

    def init_db(self):
        """SQLite 데이터베이스 및 테이블 생성"""
        conn = sqlite3.connect(self.db_filename)
        cursor = conn.cursor()
        cursor.execute('''
            CREATE TABLE IF NOT EXISTS sensor_readings (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                timestamp TEXT,
                device_id TEXT,
                led TEXT,
                temperature REAL,
                humidity REAL,
                illuminance INTEGER
            )
        ''')
        conn.commit()
        conn.close()
        print(f" DB 초기화 완료: {self.db_filename}")

    def generate_sensor_data(self):
        """가상 센서 데이터 생성(유기적인 변화 구현)"""
        self.current_temp += random.uniform(-0.5, 0.5)
        self.current_humi += random.uniform(-1.0, 1.0)

        data = {
           "timestamp": datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            "device_id": "ROOM_01",
            "sensors": {
                "led": random.choice(["ON", "OFF"]),
                "temperature": round(self.current_temp, 2),
                "humidity": round(max(0, min(100, self.current_humi)), 2), # 0~100 유지
                "illuminance": random.randint(150, 600)
            }
        }
        return data
    
    def save_to_log_and_db(self, data):
        """JSON 로그 저장 및 DB 데이터 삽입을 동시에 수행"""
        try:
            with open(self.log_filename, "a", encoding="utf-8") as f:
                json_record = json.dumps(data, ensure_ascii=False)
                f.write(json_record + "\n")
            print(f"[LOG] {data['timestamp']} - 데이터 기록 완료")
        except Exception as e:
            print(f"파일 저장 오류: {e}")
        try:
            conn = sqlite3.connect(self.db_filename)
            cursor = conn.cursor()
            s = data['sensors']
            cursor.execute('''
                INSERT INTO sensor_readings (timestamp, device_id, led, temperature, humidity, illuminance)
                VALUES (?, ?, ?, ?, ?, ?)
            ''', (data['timestamp'], data['device_id'], s['led'], s['temperature'], s['humidity'], s['illuminance']))
            conn.commit()
            conn.close()
        except Exception as e:
            print(f"DB 저장 실패: {e}")

    def run(self, interval=2):
        """시뮬레이터 시작"""
        print(f" 미니 시뮬레이터 가동 중... (중단: Ctrl+C)")
        print(f"로그 파일 위치: {self.log_filename}")
        try:
            while True:
                sensor_data = self.generate_sensor_data()
                self.save_to_log_and_db(sensor_data)
                time.sleep(interval)  # n초 간격으로 생성
        except KeyboardInterrupt:
            print("\n시뮬레이터가 중단되었습니다.")

# --- 실행부 ---
if __name__ == "__main__":
    simulator = IoT_Simulator()
    simulator.run(interval=2)  # 2초마다 데이터 생성
