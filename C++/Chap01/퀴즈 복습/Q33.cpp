#include <iostream>
#include <memory>
using namespace std;

class Cat{
//멤버를 3개 이상 만듬
private:
    string gen;
    int age;
    string col;
//Getter, Setter 만듬
public:
    void setGender(string _gen){
        gen = _gen;
    }
    string getGender(){
        return gen;
    }
    void setAge(int _age){
        age = _age;
    }
    int getAge(){
        return age;
    }
    void setColor(string _col){
        col = _col;
    }
    string getColor(){
        return col;
    }
    //디폴트 생성자와 인자가 멤버 변수만큼 있는 생성자 만듬
    Cat();
    Cat(string gen, int age, string col);
};
Cat::Cat(){
    gen = ' ';
    age = 0;
    col = ' ';
}
//생성자 변수 초기화 문법 활용
Cat::Cat(string _gen, int _age, string _col): gen(_gen), age(_age), col(_col){
}

int main()
{
    Cat mycat;

    Cat* micat = new Cat();
    micat->setGender("female"); //heap으로 만들면 ->연산자를 사용해야 한다.
    micat->setAge(2);
    micat->setColor("blue");

    cout << "이 고양이의 성별은 : " << micat->getGender() << endl;
    cout << "이 고양이의 나이은 : " << micat->getAge() << endl;
    cout << "이 고양이의 색깔은 : " << micat->getColor() << endl;

    delete micat; //객체 매모리를 회수하는 과정

    mycat.setGender("male");
    mycat.setAge(4);
    mycat.setColor("gray");

    cout << "내 고양이의 성별은 : " << mycat.getGender() << endl;
    cout << "내 고양이의 나이는 : " << mycat.getAge() << endl;
    cout << "내 고양이의 색깔은 : " << mycat.getColor() << endl;
    return 0;
}
