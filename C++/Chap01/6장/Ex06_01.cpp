#include <iostream>
#include <memory>
using namespace std;



class Calculator{

public:

    int big(int a, int b){

    if(a > b){

        return a;

    }else{

        return b;

    }
}
    int big(int a[], int size){

        int res = a[0];

        for(int i = 1; i < size; i++){

            if(res < a[i]){
                res = a[i];
            }
            return res;

        }

    }

};

int main()
{
    int array[5] = {1,9,-2,8,6};
    auto calc = make_unique<Calculator>();
    cout << calc->big(2,3) << endl;
    cout << calc->big(array, 5) << endl;

    return 0;

};
