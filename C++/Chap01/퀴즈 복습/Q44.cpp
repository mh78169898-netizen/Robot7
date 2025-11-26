//부분은 list를 사용할때 적용시키는 코드
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <list>
using namespace std;

int main() {
    vector<string> sv;
    //list<string> list;
	string names;
	for(int i=0; i<5; i++) {
        cout << "이름 >> " << endl;
		getline(cin, names);
        sv.push_back(names);
        //list.push_back(names);
	}
    sort(sv.begin(), sv.end());
    //list.sort();//오름차순,  list.sort(greater<string>())// 내림차순
    string latter = sv.back();

    cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;
    //cout << list.back() << endl;
    return 0;
}
