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
        sv.push_back(name);
    }
    sort(sv.begin(),sv.end());

    vector<string>::iterator it;
   
    for(it = sv.begin(); it != sv.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
