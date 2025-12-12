#1.생성자 만들기, 
# 맴버 private id:num, name:str, pnum:str,
# 메소드  공부하다() : 공부를 합니다.
    #getter/setter
class Student:
    def __init__(self, id, name, pnum):
        self.__id = id
        self.__name = name
        self.__pnum = pnum

    def study(self):
        print("공부를 합니다.")

    def get_Id(self):
        return self.__id
    def get_name(self):
        return self.__name
    def get_pnum(self):
        return self.__pnum        
    
    def set_id(self, new_id):
        self.__id = new_id

    def set_name(self, new_name):
        self.__name = new_name

    def set_pnum(self, new_pnum):
        self.__pnum = new_pnum
      
    
student = Student(1,'홍길동','010-1111-1111')
student.study()
print(student.get_Id())
print(student.get_name())
print(student.get_pnum())
student.set_id(2)
student.set_name('김수한')
student.set_pnum('010-2222-3333')
print(student.get_Id())
print(student.get_name())
print(student.get_pnum())
