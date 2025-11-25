#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int n){
    cout << n << ' ';
}

int main()
{
   vector <int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    auto vec = [](int n){
    if(n % 2 == 1){
        cout << n << '\t';
    }
   };

   for_each(v.begin(), v.end(),vec);
   cout << endl;
    
   return 0;
}
