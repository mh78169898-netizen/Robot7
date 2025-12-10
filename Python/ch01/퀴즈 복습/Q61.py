import random

sung = list('김이박최조성한서')
s_name = list('민하수준현동훈명요지')
id = 0
with open("students.csv", "w") as file:
    file.write('id,name,math,english\n')
    for i in range(1000):
        id += 1
        name = random.choice(sung) + random.choice(s_name) + random.choice(s_name)
        math = random.randrange(0,100)
        english = random.randrange(40,100)
        file.write("{}, {}, {}, {}\n".format(id ,name ,math ,english))
