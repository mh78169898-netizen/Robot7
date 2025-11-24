#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> sv;
    string name;

    cout << "이름을 5개 입력하라" << endl;
    for(int i = 0; i < 5; i++){
        cout << i + 1 << ">>";
        getline(cin, name);
        sv.push_back(name); //벡터 메모리(요소) 추가
    }
    sort(sv.begin(),sv.end()); //

    vector<string>::iterator it;
   
    // for(it = sv.begin(); it != sv.end(); it++){
    //     cout << *it << ' ';
    // }
    for(string s : sv){
        cout << s << "   ";
    } // for each 구문
    cout << endl;
    return 0;
}
