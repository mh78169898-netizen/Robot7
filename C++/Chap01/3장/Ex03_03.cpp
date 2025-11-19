#include <iostream>
using namespace std;

class Circle{
public:
    //1.멤버 변수
     int rid;
     string color;
    //2.생성자
    Circle(){
        this->rid = 1;
        cout << "circle의 반지름 : " << rid << endl;
    } //default 생성자
    Circle(int r){
        rid = r;
        cout << "circle의 반지름 : " << rid << endl;
    }
     Circle(int r, string c){
        rid = r;
        color = c;
        cout << "circle의 반지름 : " << rid << " 색상 : " << color << endl;
    }
    //3.멤버 메소드
};

int main()
{    
    Circle donut;
    Circle pizza(30);
    Circle tire(10, "red");

    return 0;
}
