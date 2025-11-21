#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cout << "입력할 정수의 개수는? : " ;
    cin >> n;
    if(n <= 0){
        return 0;
    }
    int* p = new int [n];
    for(int i = 0; i < n; i++){
        cout << i+1 << "번째 정수 : ";
        cin >> p[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + p[i];
    }
    cout << "평균 : " << sum / n << endl;
    delete [] p; //배열 타입을 먼저 적고, 변수를 다음에 적는다.
    
    return 0;
}
