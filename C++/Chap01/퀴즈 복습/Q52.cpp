--헤리포트의 마법을 전략패턴을 사용해서 동작시켜 주세요.--
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class MagicStrategy{
public:
    virtual void cast() = 0; //가장 핵심 함수
    virtual ~MagicStrategy() = default;
};
class FireMagic : public MagicStrategy
{
public:
    void cast() override{
        cout << "해리가 화염 마법을 시전합니다." << endl;
    }
};
class IceMagic : public MagicStrategy
{
public:
    void cast() override{
        cout << "해리가 얼음 마법을 시전합니다." << endl;
    }
};

class Harry
{
private:
    string name;
    MagicStrategy* currentMagic = nullptr;
public:
    Harry(string name) : name(name){}
    void setMagic(MagicStrategy& s){
        currentMagic = &s;
    }
    void Attack(){
        if(!currentMagic){
            cout << "(경고) 마법없음\n";
            return;
        }
        currentMagic->cast();
    }
   
};

int main()
{
    Harry hero("해리 포터");

    FireMagic fire;
    IceMagic ice;
    int choice = -1;
   
    while(true)
    {
        cout << "=== 해리 포터 마법 전투 시뮬레이터 ===\n";
        cout << "1.화염 마법 선택\n";
        cout << "2.얼음 마법 선택\n";
        cout << "3.공격 실행\n";
        cout << "0. 종료\n"; 
        cin >> choice;

         switch(choice){
        case 1:
            hero.setMagic(fire);
            cout << "[시스템]해리가 화염 마법을 준비합니다." << endl;
            break;
        case 2:
            hero.setMagic(ice);
            cout << "[시스템]해리가 얼음 마법을 준비합니다." << endl;
            break;
        case 3:
            hero.Attack();
            break;
        case 0:
            cout << "프로그램을 종료합니다.\n";
            return 0;
        default:
            cout << "잘못된 메뉴입니다. 다시 입력하세요." << endl;
            break;
    }
}   
    return 0;
}
