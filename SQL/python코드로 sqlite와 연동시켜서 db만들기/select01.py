import sqlite3

path = '/mnt/c/Users/User/databases/'
conn = sqlite3.connect(path + 'test3.db')
cur = conn.cursor()

sql = "SELECT ID, Name, Pnumber FROM person;" #여기(quere)서는 대/소문자를 구분함
cur.execute(sql)

rows = cur.fetchall() #튜플 타입으로 레코드 정보를 읽어온다.

for row in rows:
    print(row)

conn.close()
