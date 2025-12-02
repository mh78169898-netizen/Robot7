#include <iostream>
using namespace std;

class Power{
private:
    int kick;
    int punch;
public:
    Power(int kick=0, int punch=0){
        this->kick = kick;
        this->punch = punch;
    }
    void show(){
        cout << "kick: " << kick << ", punch: " << punch << endl;
    }
    //연산자 오버로딩!!!!!
    Power operator+ (Power other){
        Power tmp;
        tmp.kick = this->kick + other.kick;
        tmp.punch = this->punch + other.punch;
        return tmp;
    }
    Power operator- (Power other){
        Power tmp;
        tmp.kick = this->kick - other.kick;
        tmp.punch = this->punch - other.punch;
        return tmp;
    }
};

int main()
{
    Power a(3,5), b(4,6),c;
    c = a - b;
    a.show();
    b.show();
    c.show();
    return 0;
}
