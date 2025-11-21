//클래스 배열
#include <iostream>
#include <cstdlib>
using namespace std;

class Circle{
public:
    int radius;
    Circle(){
        radius = 1;
    }
    Circle(int r){
        radius = r;
    }
    void setR(int r){
        radius = r;
    }
    double getArea(){
        return 3.14*radius*radius;
    }
};

int main()
{
    Circle cir[3]; //오브젝트 스택
    cir[0].setR(10);
    cout << "넓이 : " << cir[0].getArea() << endl;

    Circle* p;
    p = cir;
    cout << "넓이 : " << p[0].getArea() << endl;

    Circle* cir2[3];//object heap
    cir2[0] = new Circle(); //배열요소에 객체 생성이 필수
    cir2[0]->setR(10);
    cout << "넓이 : " << cir2[0]->getArea() << endl;
    
    delete cir2[0];

    return 0;
}
