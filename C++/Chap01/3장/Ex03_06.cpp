#include <iostream>

using namespace std;

class Rectangle{
public:
    int wit;
    int hei;
    //생성자 3개 만들기
    Rectangle():wit(1), hei(1){
    }
    Rectangle(int len){
        wit = len;
        hei = len;
    }
    Rectangle(int _wit, int _hei){
        wit = _wit;
        hei = _hei;
    }
    //함수 1개 만들기
    bool isSquare(){
        if(wit == hei){
            return true;
        }else{
            return false;
        }
    }
    
};

int main()
{
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);
    if(rect1.isSquare()) cout << "rect1은 정사각형이다. " << endl;
    if(rect2.isSquare()) cout << "rect2은 정사각형이다. " << endl;
    if(rect3.isSquare()) cout << "rect3은 정사각형이다. " << endl;

    return 0;
}
