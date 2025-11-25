-vector 컨테이너 사용법-
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;

    for(it=v.begin(); it != v.end(); it++){ //iterator를 사용해서 모든 원소 탐색
        int n = *it; //it가 가리키는 원소 값 리턴
        n = n*2; // 2를 곱해줌
        *it = n; //it가 가리키는 원소에 값 쓰기
    }

    for(it = v.begin(); it != v.end(); it++){ //벡터 v의 모든 원소 출력
        cout << *it << ' ';
    }
    cout << endl;
    
    return 0;
}
-간략화 버전
  #include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;//순환자 선언, 순환자는 포인터 변수

    for(it = v.begin(); it != v.end(); it++){ //벡터 v의 모든 원소 출력
        cout << *it << ' ';
    }
    cout << endl;
    
    return 0;
}
