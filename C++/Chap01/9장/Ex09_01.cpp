#include <iostream>
#include <memory>
using namespace std;

class Parent
{
public:
    virtual void f(){
        cout << "Parent::f() called" << endl;
    }
};

class Child : public Parent
{
public:
    void f() override{
        cout << "Child::f() called" << endl;
    }
};

int main()
{
    // Child d; //스텍에 객체가 생성
    // Child* pDer; //포인터 변수
    // pDer = &d; //객체의 시작 주소를 pDer에 대입
    // pDer->f();
    unique_ptr<Child> child = make_unique<Child>();
    child->f();

    unique_ptr<Parent> p = make_unique<Child>();
    p->f();

    return 0;
}
