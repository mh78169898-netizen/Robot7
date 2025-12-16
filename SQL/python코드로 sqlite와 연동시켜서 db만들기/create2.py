import sqlite3

#1.연결객체를 만들어라. DBMS회가 driver와 api를 제공한다.
#Server/Client -- FTP(wed,hdd)/MSG Service/Mail...

path = '/mnt/c/Users/User/databases/'
conn = sqlite3.connect(path + 'test3.db')
cur = conn.cursor() #SQL 사용가능한 객체

#SQL 실행
quere = '''
CREATE TABLE "person" (
	"ID"	INTEGER,
	"Name"	TEXT NOT NULL,
	"Pnumber"	TEXT NOT NULL,
	PRIMARY KEY("ID" AUTOINCREMENT)
);
'''

cur.execute(quere)

#sqlite는 commit을 연결객체에서 한다.
conn.commit() #save 단, save후에는 변경 불가
conn.close()

print('person 테이블이 생성되었습니다.')
