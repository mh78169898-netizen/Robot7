import sqlite3

path = '/mnt/c/Users/User/databases/'
conn = sqlite3.connect(path + 'test3.db')
cur = conn.cursor()

sql = "SELECT ID, Name, Pnumber FROM person;" #여기(quere)서는 대/소문자를 구분함
cur.execute(sql)

rows = cur.fetchall()

for row in rows:
    person_id = row[0]      # id
    name = row[1]           # name
    pnumber = row[2]        # pnumber

    print(person_id, name, pnumber)

conn.close()
