#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // vector<int> v = {1,1,1,2,2,2,3,3,3};
    
    // vector<int>::iterator it;
    // for(it = v.begin(); it != v.end();){
    //     if(it + 1 != v.end() && *it == *(it + 1)){
    //        it = v.erase(it);
    //     }else{
    //         it++;
    //     }
    // }
    // for (int e : v) {
    //     cout << e << " "; 
    // }
    // cout << endl;

    vector<int> v = {1,1,1,2,2,2,3,3,3};
    //1.만약 원소들의 값이 정렬되어 있지 않다면?
    sort(v.begin(), v.end());
    //2.중복 찾기
    auto it_v = unique(v.begin(), v.end());
    //3.중복 제거
    v.erase(it_v, v.end());
    for(int i : v){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
