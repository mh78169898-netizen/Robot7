import sqlite3

path = '/mnt/c/Users/User/databases/'
conn = sqlite3.connect(path + 'test3.db')
cur = conn.cursor() #SQL 사용가능한 객체

#SQL 실행
quere = '''
INSERT INTO person (Name, Pnumber)
VALUES (?, ?);
'''

cur.execute(quere, ('을지문덕', '010-4444-4444'))

#sqlite는 commit을 연결객체에서 한다.
conn.commit() #save 단, save후에는 변경 불가
conn.close()

print('person 테이블에 데이터를 삽입했습니다.')
