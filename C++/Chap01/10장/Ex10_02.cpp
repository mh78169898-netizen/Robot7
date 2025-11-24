두 값을 매개 변수로 받아 큰 값을 리턴하는 제네릭 함수 bigger()를 작성하기
#include <iostream>
using namespace std;

template<class T>
T bigger(T a, T b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main()
{
    int a = 20, b = 50;
    char c = 'a', d = 'z';
    cout << "bigger(20, 50)의 결과는 " << bigger(a, b) << endl;
    cout << "bigger('a', 'z')의 결과는 " << bigger(c, d) << endl;    
    return 0;
}
