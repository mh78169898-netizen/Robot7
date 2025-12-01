45-1
#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

class Calculator
{
private:
    int a;
    int b;
public:
    void inputNum(){
        int a, b;
        cout << "두 수를 입력하세요 : ";
        cin >> a >> b;
        this->a = a;
        this->b = b;
    }
    int plus(){
        return a + b;
    }
    int minus(){
        return a - b;
    }
    int mul(){
        return a * b;
    }
    double div(){
        return (double)a / b;
    }
};

int main()
{
    unique_ptr<Calculator> cal = make_unique<Calculator>();
    cal->inputNum();
    cout << "Plus : " << cal->plus() << endl;
    cout << "Minus : " << cal->minus() << endl;
    cout << "Multiple : " << cal->mul() << endl;
    cout << "Divide : " << cal->div() << endl;
    return 0;
}

45-2
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
using namespace std;

class Hero{
public:
    virtual void attack(){
        cout << "영웅 공격하다!" << endl;
    }
};
class Knight : public Hero{
public:
    void attack() override{
        cout << "기사 공격하다!" << endl;
    }
};
class Archer : public Hero{
public:
    void attack() override{
        cout << "궁수 공격하다!" << endl;
    }
};
class Wizard : public Hero{
public:
    void attack() override{
        cout << "마법사 공격하다!" << endl;
    }
};

int main()
{
   vector<unique_ptr<Hero>> party;
    party.push_back(make_unique<Hero>());
    party.push_back(make_unique<Knight>());
    party.push_back(make_unique<Archer>());
    party.push_back(make_unique<Wizard>());

    for(const auto& member : party){
        member->attack();
    }
    
    return 0;
}
