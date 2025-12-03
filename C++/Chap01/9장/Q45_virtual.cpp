#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Hero
{
public:
    virtual void attack(){
        cout << "Hero Attack!" << endl;
    }
};
class Knight : public Hero
{
public:
    void attack() override{
        cout << "Knight Attack!" << endl;
    }
};
class Archer : public Hero
{
public:
    void attack() override{
        cout << "Archer Attack!" << endl;
    }
};
class Wizard : public Hero
{
public:
    void attack() override{
        cout << "Wizard Attack!" << endl;
    }
};

int main()
{
    vector<Hero*> hero_list; //stack의 값 -- Hero객체들이 있는 주소들을 모은 꾸러미
    unique_ptr<Hero> k = make_unique<Knight>(); //객체가 heap -- 코딩하는 곳은 stack
    unique_ptr<Hero> a = make_unique<Archer>(); //객체가 heap -- 코딩하는 곳은 stack(a 변수의 값이 주소 Archer 객체가 있는 시작주소)
    unique_ptr<Hero> w = make_unique<Wizard>(); //객체가 heap -- 코딩하는 곳은 stack(w변수는 값이 주소-> Wizard객체가 있는 시작 주소값)
    hero_list.push_back(k.get());
    hero_list.push_back(a.get());
    hero_list.push_back(w.get());

    for(auto h : hero_list){
        h->attack();
    }
    return 0;
}
