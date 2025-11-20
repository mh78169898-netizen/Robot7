#include <iostream>

using namespace std;
class Car
{
    public:
    //1.맴버변수
    int speed;
    string brand;
    string color;
    //2.생성자          생성자는 객체의 탄생과 관련되어있다.
    Car():speed(50), brand("기아"),color("빨간색"){ //default생성자. 생성자가 하나도 없으면 컴퓨터가 자동으로 생성해줌
    }
    //3.멤버 메소드
    string run(){
        return "달린다~~~!!\n";
    }
};

int main()
{
    Car myCar;
    cout << "mycar.speed : " << myCar.speed << endl;
    cout << "mycar.brand : " << myCar.brand << endl;
    cout << "mycar.color : " << myCar.color << endl;
    cout << "run : " << myCar.run() << endl;

    return 0;
}
