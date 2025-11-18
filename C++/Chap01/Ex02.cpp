//bool 타입 사용
#include <iostream>

int main()
{
    bool b1 = true;
    bool b2 = false;

    std::cout << "b1 = " << b1 << "\n" << std::endl;
    std::cout << "b2 = " << b2 << "\n" << std::endl;
}

//묵시적,명시적인 형변환

    int a = 100;
    double b = 3.14;

    b = a;// 묵시적인 형변환
    a = (int)b;//명시적인 형변환
