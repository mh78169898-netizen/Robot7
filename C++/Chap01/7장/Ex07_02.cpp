#include <iostream>
using namespace std;

class Rect;//전방 선언
bool equals(Rect r, Rect s);//함수 선언

class Rect
{
private:
    int width;
    int height;
public:
    Rect(int width, int height) : width(width), height(height) {}//생성자
    friend bool equals(Rect r, Rect s); //private 멤버 접근을 위해 friend 선언
};
bool equals(Rect r, Rect s){ //함수 구현
    if(r.width == s.width && r.height == s.height)
        return true;
    else
        return false;
}

int main()
{
    Rect rect1(3,4), rect2(3,4);
    if(equals(rect1, rect2))
        cout << "같다" << endl;
    else
        cout << "다르다" << endl;
    return 0;
}
