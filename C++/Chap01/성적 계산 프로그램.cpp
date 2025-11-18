#include <iostream>
#include <ios>
#include <iomanip> //c++에서 소숫점 구할때 사용
#include <string>
//P.76 C++로 성적 계산 프로그램
int main()
{
    using namespace std;
    //이름 입력
    cout << "이름을 입력하세요 : ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    //중간,기말 성적 입력
    cout << "중간,기말 성적을 입력하세요: ";
    double mid, fin;
    cin >> mid >> fin;
    //과제 점수 입력
    cout << "과제 점수를 입력하고 파일의 끝(Ctrl + Z)을 입력하세요: ";

    int count = 0;
    double sum = 0;

    double  x;//과제 점수

    while (cin >> x) {  //EOF(-1)을 입력하면 거짓으로 판별, 루프 벗어남
        ++count;
        sum += x;
    }
    //결과 출력
    streamsize prec = cout.precision();
    cout << "당신의 성적은 " << setprecision(3) 
        << 0.2 * mid + 0.4 * fin + 0.4 * sum / count 
        << setprecision(prec) << endl;

    //printf("%.2lf")로 소숫점을 찍을 수 있다.

    return 0;

}

