import sqlite3
import logging #로깅 모듈 임포트 부분

#로그 설정 부분
logging.basicConfig(
    filename='address_book.log',
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s -%(message)s',
    datefmt='%Y-%m-%d %H:%M:%S'
)

dbPath = "/mnt/c/Users/User/databases/test7.db"


class Person:
    def __init__(self, id=None, name="", pnumber=""):
        self.id = id
        self.name = name
        self.pnumber = pnumber

    def __str__(self):
        return f"Person(id={self.id}, name={self.name}, pnumber={self.pnumber})"


class PersonRepository:
    def __init__(self, dbPath: str):
        self.dbPath = dbPath

    def getConnection(self):
        return sqlite3.connect(self.dbPath)

    def createTable(self):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        CREATE TABLE IF NOT EXISTS Person (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL,
            Pnumber TEXT NOT NULL
        );
        """

        cur.execute(sql)
        conn.commit()
        conn.close()

    def insert(self, person: Person):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        INSERT INTO Person (Name, Pnumber)
        VALUES (?, ?);
        """

        cur.execute(sql, (person.name, person.pnumber))
        conn.commit()

        person.id = cur.lastrowid
        logging.info(f"데이터 추가됨: ID={person.id}, Name={person.name}") #로그 기록 코드
        conn.close()

    def findAll(self):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "SELECT ID, Name, Pnumber FROM Person ORDER BY ID;"
        cur.execute(sql)

        persons = []
        for row in cur:  # (ID, Name, Pnumber)
            persons.append(Person(row[0], row[1], row[2]))

        conn.close()
        return persons
    def update(self, person: Person):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = """
        UPDATE Person
        SET Name = ?, Pnumber = ?
        WHERE ID = ?
        """

        cur.execute(sql, (person.name, person.pnumber, person.id))
        logging.info(f"데이터 수정됨: ID={person.id}, Name={person.name}으로 변경") #로그 기록 코드
        conn.commit()
        conn.close()
    
    def delete(self, person_id: int):
        conn = self.getConnection()
        cur = conn.cursor()

        sql = "DELETE FROM Person WHERE ID = ?;"
        cur.execute(sql, (person_id,))
        logging.info(f"데이터 삭제됨: ID={person_id}") #로그 기록 코드
        conn.commit()
        conn.close()


def main():
    repo = PersonRepository(dbPath)
    repo.createTable()

    while True:
        print("\n=== Person Address Book ===")
        print("1. 사람 추가")
        print("2. 전체 조회")
        print("3. 정보 수정")
        print("4. 사람 삭제")
        print("5. 로그 확인")
        print("0. 종료")

        choice = input("선택: ").strip()

        match choice:
            case "1":
                name = input("이름: ").strip()
                pnumber = input("전화번호: ").strip()

                person = Person(name=name, pnumber=pnumber)
                repo.insert(person)

                print("저장 완료:", person)

            case "2":
                persons = repo.findAll()
                print("\n--- 전체 목록 ---")
                for p in persons:
                    print(p)
            case "3":
                del_id = input("수정할 사람의 ID를 입력하세요: ").strip()
                if del_id.isdigit():
                    new_name = input("수정할 이름: ").strip()
                    new_pnumber = input("수정할 전화번호: ").strip()

                    updated_person = Person(id=int(del_id), name=new_name, pnumber=new_pnumber)
                    repo.update(updated_person)
                    print(f"ID {del_id}번 정보가 성공적으로 수정되었습니다.")

            case "4":
                del_id = input("삭제할 사람의 ID를 입력하세요: ").strip()
                repo.delete(int(del_id))
                print(f"ID {del_id}번 데이터가 삭제되었습니다.")

            case "5":
                print("\n---최근 작업 이력(LOG)---")
                try:
                    with open('address_book.log', 'r', encoding='utf-8') as f:
                        lines = f.readlines()
                        for line in lines[-10:]: #가장 최근 라인 10개만 출력
                            print(line.strip())
                except FileNotFoundError:
                    print('로그 파일 없음.')

            case "0":
                print("프로그램 종료")
                break

            case _:
                print("잘못된 입력입니다.")


if __name__ == "__main__":
    main()
