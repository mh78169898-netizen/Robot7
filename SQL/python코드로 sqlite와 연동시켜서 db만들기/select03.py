import sqlite3

path = '/mnt/c/Users/User/databases/'
conn = sqlite3.connect(path + 'test3.db')
conn.row_factory = sqlite3.Row #튜플이 아니라 딕셔너리로 가져옴
cur = conn.cursor()

cur.execute("SELECT ID, Name, Pnumber FROM person;")

for row in cur:
    print(row["ID"], row["Name"], row["Pnumber"])

conn.close()
