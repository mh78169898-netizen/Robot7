//위임 생성자 호출
#include <iostream>
using namespace std;

class Circle{
public:
    //1.멤버 변수
     int rid;
     string color;
    //2.생성자
    Circle():rid(1),color("red")//초기화 변수
    { 
        cout << "circle의 반지름 : " << rid << endl;
        cout << "circle의 색상 : " << color << endl;
    }
    Circle(int r):rid(r)
    {
        cout << "circle의 반지름 : " << rid << endl;
    }
    //3.멤버 메소드
};

int main()
{    
    Circle donut;
    Circle pizza(30);

    return 0;
}
