#include <iostream>
#include <memory>
using namespace std;

class Cat{
private:
    string gen;
    int age;
    string col;
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
    Cat();
    Cat(string gen, int age, string col);
};
Cat::Cat(){
    gen = ' ';
    age = 0;
    col = ' ';
}
Cat::Cat(string _gen, int _age, string _col): gen(_gen), age(_age), col(_col){
}

int main()
{
    Cat mycat;

    Cat* micat = new Cat();
    micat->setGender("female");
    micat->setAge(2);
    micat->setColor("blue");

    cout << "이 고양이의 성별은 : " << micat->getGender() << endl;
    cout << "이 고양이의 나이은 : " << micat->getAge() << endl;
    cout << "이 고양이의 색깔은 : " << micat->getColor() << endl;

    delete micat;

    mycat.setGender("male");
    mycat.setAge(4);
    mycat.setColor("gray");

    cout << "내 고양이의 성별은 : " << mycat.getGender() << endl;
    cout << "내 고양이의 나이는 : " << mycat.getAge() << endl;
    cout << "내 고양이의 색깔은 : " << mycat.getColor() << endl;
    return 0;
}
