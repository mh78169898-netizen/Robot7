#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string song;//문자열 변수 선언
    song = "Falling in love with you";//문자열 변수 초기화
    string elvis("Elvis Presly");//선언과 동시에 문자열 초기화
    string singer;//문자열 변수 선언만

    cout << song << "를 부를 가수는?" << endl;
    cout << "(힌트 : 첫 글자는"  << elvis[0] << ")?";

    getline(cin, singer);//문자열 입력 방법중 가장 많이 사용함
    if(singer == elvis){
        cout << "맞았습니다." << endl;
    }else{
        cout << "틀렸습니다." + elvis + "입니다." << endl;
    }
    return 0;
}
