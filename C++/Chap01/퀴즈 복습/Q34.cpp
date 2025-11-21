#include <iostream>
using namespace std;

class Shape{
public:
   //draw함수를 만드시오
   virtual void draw(){
    cout << "도형을 그리다." << endl;
   }

};
//Shape를 상속받는 Triangle class를 만드시오
//Shape를 상속받는 Rectangle class를 만드시오
//Shape를 상속받는 Circle class를 만드시오

class Triangle : public Shape{
public:
    void draw() override {
        cout << "삼각형을 그리다." << endl;
    }
};
class Rectangle : public Shape{
public:
    void draw() override {
        cout << "사각형을 그리다." << endl;
    }
};
class Circel : public Shape{
public:
    void draw() override {
        cout << "원을 그리다." << endl;
    }
};


int main()
{
    Shape s;
    s.draw();

    Triangle t;
    t.draw();

    Rectangle r;
    r.draw();

    Circel c;
    c.draw();

    return 0;
}
