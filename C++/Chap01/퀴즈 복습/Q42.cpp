#include <iostream>
using namespace std;

class Lion{
public:
    void roar(){
        cout << "키메라는 울부짖었다!!!" << endl;
    }
};

class IWing{
public:
    void fly(){
        cout << "키메라는 날아올랐다!!!" << endl;
    }
};

class Chimaera : public Lion, public IWing{
};

int main()
{
    Chimaera ch;
    ch.roar();
    ch.fly();

    return 0;
}
