#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    //1.revers 사용
    string str;
    string str2;
    getline(cin, str);
    //문자열 string 복사
    str2.resize(str.size());
    copy(str.begin(), str.end(), str2.begin());
    reverse(str.begin(), str.end()); 
    //입력받은 문자열을 뒤집음
    cout << str;
    cout << endl;

    //2.고전적인 방법
    int length = str2.size();
    for(int i = length - 1; i >= 0; i--){
        // cout << str2[i]; //1번 방법
        cout << str2.at(i); //2번 방법
    }

    return 0;
};
