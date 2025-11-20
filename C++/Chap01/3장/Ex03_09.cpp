#include <iostream>
using namespace std;

class Person{
private:
    int num;
    string name;
public:
    Person(){}
    Person(int _num, string _name){
        num = _num;
        name = _name;
    }
    //Getter,Setter
    void setNum(int _num){
        num = _num;
    }
    int getNum(){
        return num;
    }
    void setName(string _name){
        name = _name;
    }
    string getName(){
        return name;
    }

};

int main()
{
    Person sam(1, "샘");
    cout << "이름 : " << sam.getName() << endl;
    cout << "주민 번호 : " << sam.getNum() << endl;

    Person jane;
    jane.setName("jane");
    jane.setNum(2);
    cout << "이름 : " << jane.getName() << endl;
    cout << "주민 번호 : " << jane.getNum() << endl;
    return 0;
}
