#include <iostream>
using namespace std;
//4칙연산

class Calculator{
private:
    int a;
    int b;

public:
   Calculator(){}

   int plu(int a, int b){
    return a + b;
   }
   int min(int a, int b){
    return a - b;
   }
   int mul(int a, int b){
    return a * b;
   }
   double div(int a, int b){
    return (double)a / b;
   }
};

int main()
{
    Calculator calculator;

    cout << "덧셈 : " << calculator.plu(5,7) << endl;
    cout << "뺄셈 : " << calculator.min(5,7) << endl;
    cout << "곱셈 : " << calculator.mul(5,7) << endl;
    cout << "나눗셈 : " << calculator.div(5,7) << endl;
    return 0;
}
