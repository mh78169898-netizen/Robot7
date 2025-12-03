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
    vector<Hero*> hero_list;
    unique_ptr<Hero> k = make_unique<Knight>();
    unique_ptr<Hero> a = make_unique<Archer>();
    unique_ptr<Hero> w = make_unique<Wizard>();
    hero_list.push_back(k.get());
    hero_list.push_back(a.get());
    hero_list.push_back(w.get());

    for(auto h : hero_list){
        h->attack();
    }
    return 0;
}
