#include <iostream>
using namespace std;

class Circle{
public:
    int radius;
    // Circle(){} (1)
    //인자가 1개 있는 생성자만 만들어봅시다.
    Circle(int r){
        radius = r;
    }

    double getArea(){
        return 3.14*radius*radius;
    }
};

int main()
{
    // Circle circlrArray[3]; 이 부분이 문제
    Circle circlrArray[3] = {Circle(10), Circle(20), Circle(30)};//(2)
    for(int i=0; i<3; i++){
        cout << i << "번째 넓이 : " << circlrArray[i].getArea() << endl;
    }
    cout << "프로그램이 동작하였습니다." << endl;
    return 0;
}
//해결법
//(1).디폴트 생성자 생성
//(2).배열의 각 원소 객체당 생성자를 지정
