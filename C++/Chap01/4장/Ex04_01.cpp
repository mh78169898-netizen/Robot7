#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

class Circle{
public:
    int radius;
    double getArea(){
        return 3.14*radius*radius;
    }
};

int main()
{
   Circle donut; //오브젝트,인스턴스
   cout << "donut : 넓이 : " << donut.getArea() << endl;

   Circle* p;//포인터변수(객체를 가리키는 포인터)
   p = &donut; //stack
   cout << "p : 넓이 : " << p->getArea() << endl;
   cout << "p : 넓이 : " << (*p).getArea() << endl; //원 문법은 이게 맞음

   //C#이나 java식 표현
   Circle* donut2 = new Circle(); //heap
   cout << "donut2 : 넓이 : " << donut2->getArea() << endl;
   cout << "donut2 : 넓이 : " << (*donut2).getArea() << endl;
   delete donut2;
   
    return 0;
}
