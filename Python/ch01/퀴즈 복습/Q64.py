class Student:
    def __init__(self, id, name):
        self.__id = id
        self.__name = name

    @property
    def student(self, id, name):
        return self.__id, self.__name
    

chulsoo = Student(1, '철수')
chulsoo.id = 2
chulsoo.name = ('철얼~쑤')
print(chulsoo.id, ' : ', chulsoo.name)

