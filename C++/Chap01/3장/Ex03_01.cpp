#include <iostream>

class Circle{
    public:
    //1.멤버 변수
    int rid;
    //2.생성자
    //없으면 컴파일러가 컴파일시 자동으로 생성
    //3.멤버 함수
    double getA(){
         return 3.14*rid*rid;
    }
};

// double Circle::getA(){
//     return 3.14*rid*rid;
// }

int main()
{
    using namespace std;
    
    Circle donut; //stack에 객체가 생성됨

    donut.rid = 1;

    double area = donut.getA();
    cout << "donut 면적은 " << area << endl;
    // cout << "donut 면적은 " << donut.getA() << endl;

    Circle pizza;
    pizza.rid = 30;
    area = pizza.getA();
    cout << "pizza 면적은 " << area << endl;
    // cout << "pizza 면적은 " << pizza.getA() << endl;
    return 0;
}
