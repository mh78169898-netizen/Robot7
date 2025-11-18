#include <iostream>


int main()
{
    using namespace std;
    //점수입력
    int s, div;
    cout << "점수를 입력하세요 : ";
    cin >> s;
    //예외처리
    if (s > 100 || s < 0) {
        cout << "다시 입력!!!";
        return 0;
    }
    //로직, 출력
    div = s / 10;
    switch (div) {
    case 10:
    case 9:
        cout << "A입니다.";
        break;
    case 8:
        cout << "B입니다.";
        break;
    case 7:
        cout << "C입니다.";
        break;
    case 6:
        cout << "D입니다.";
        break;
    default:
        cout << "F입니다.";
        break;
    }

    return 0;
}
