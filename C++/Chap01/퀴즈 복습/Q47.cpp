팔라딘.hpp
#include <iostream>
#include <string>
using namespace std;

class Paladin
{
private:
    string name;
    string leftWeapon;
    string rightWeapon;
    string leftRing;
    string rightRing;
    string armor;
    string amulet;

    Paladin(const string& name,
            const string& leftWeapon,
            const string& rightWeapon,
            const string& leftRing,
            const string& rightRing,
            const string& armor,
            const string& amulet)
        : name(name),
          leftWeapon(leftWeapon),
          rightWeapon(rightWeapon),
          leftRing(leftRing),
          rightRing(rightRing),
          armor(armor),
          amulet(amulet)
    {
    }
public:
   class Builder
   {
   private:
    string name;

    string leftWeapon = "맨손";
    string rightWeapon = "맨손";
    string leftRing = "없음";
    string rightRing = "없음";
    string armor = "천 갑옷";
    string amulet = "없음";

   public:
    Builder(const string& name) : name(name) {};
    Builder& setLeftWeapon(const string& Weapon)
    {
        leftWeapon = Weapon;
        return *this;
    }
    Builder& setRightWeapon(const string& Weapon)
    {
        rightWeapon = Weapon;
        return *this;
    }
    Builder& setLeftRing(const string& ring)
    {
        leftRing = ring;
        return *this;
    }
    Builder& setRightRing(const string& ring)
    {
        rightRing = ring;
        return *this;
    }
    Builder& setArmor(const string& armor)
    {
        this->armor = armor;
        return *this;
    }
    Builder& setAmulet(const string& amulet)
    {
        this->amulet = amulet;
        return *this;
    }

    Paladin build() const{
        return Paladin(name, leftWeapon, rightWeapon, leftRing, rightRing, armor, amulet);
    }
   };
   void print() const{
    cout << "=====팔라딘 장비 상태 =====" <<  endl;
    cout << "이름       : " << name << endl;
    cout << "왼손 무기   : " << leftWeapon << endl;
    cout << "오른손 무기    : " << rightWeapon << endl;
    cout << "왼손 반지      : " << leftRing << endl;
    cout << "오른손 반지    : " << rightRing << endl;
    cout << "갑옷           : " << armor << endl;
    cout << "목걸이         : " << amulet << endl;
   }
};


원소술사.hpp

#include <iostream>
#include <string>
using namespace std;

class Sorcerer
{
private:
    string name;
    string leftWeapon;
    string rightWeapon;
    string leftRing;
    string rightRing;
    string armor;
    string amulet;
    Sorcerer(const string& name,
            const string& leftWeapon,
            const string& rightWeapon,
            const string& leftRing,
            const string& rightRing,
            const string& armor,
            const string& amulet)
        : name(name),
          leftWeapon(leftWeapon),
          rightWeapon(rightWeapon),
          leftRing(leftRing),
          rightRing(rightRing),
          armor(armor),
          amulet(amulet)
    {
    }
public:
   class Builder
   {
   private:
    string name;

    string leftWeapon = "맨손";
    string rightWeapon = "맨손";
    string leftRing = "없음";
    string rightRing = "없음";
    string armor = "천 로브";
    string amulet = "없음";

   public:
    Builder(const string& name) : name(name) {};
    Builder& setLeftWeapon(const string& Weapon)
    {
        leftWeapon = Weapon;
        return *this;
    }
    Builder& setRightWeapon(const string& Weapon)
    {
        rightWeapon = Weapon;
        return *this;
    }
    Builder& setLeftRing(const string& ring)
    {
        leftRing = ring;
        return *this;
    }
    Builder& setRightRing(const string& ring)
    {
        rightRing = ring;
        return *this;
    }
    Builder& setArmor(const string& armor)
    {
        this->armor = armor;
        return *this;
    }
    Builder& setAmulet(const string& amulet)
    {
        this->amulet = amulet;
        return *this;
    }

    Sorcerer build() const{
        return Sorcerer(name, leftWeapon, rightWeapon, leftRing, rightRing, armor, amulet);
    }
   };
   void print() const{
    cout << "=====소서러 장비 상태 =====" <<  endl;
    cout << "이름       : " << name << endl;
    cout << "왼손 무기   : " << leftWeapon << endl;
    cout << "오른손 무기    : " << rightWeapon << endl;
    cout << "왼손 반지      : " << leftRing << endl;
    cout << "오른손 반지    : " << rightRing << endl;
    cout << "갑옷           : " << armor << endl;
    cout << "목걸이         : " << amulet << endl;
   }
};

메인 코드.cpp

#include <iostream>
#include <string>
using namespace std;

#include "paladin.hpp"
#include "sorcerer.hpp"

int main() {
    // 1) 해머딘 세팅 예시
    Paladin hammerdin = Paladin::Builder("해머딘")
        .setLeftWeapon("스피릿 크리스탈 소드")   // 왼손: 스피릿
        .setRightWeapon("스피릿 성기사 방패")     // 오른손: 스피릿 방패
        .setLeftRing("패캐 링")                  // 왼손 반지
        .setRightRing("레번 프로스트")           // 오른손 반지
        .setArmor("수수께끼 아머")               // 갑옷
        .setAmulet("마라의 만화경")              // 목걸이
        .build();
    hammerdin.print();
    cout << endl;

    Sorcerer mage = Sorcerer::Builder("원소술사")
        .setLeftWeapon("기본 지팡이")
        .setRightWeapon("기본 방패")
        .setLeftRing("기본 반지")
        .setRightRing("기본 반지") 
        .setArmor("천 갑옷")
        .setAmulet("기본 목걸이")
        .build();
    mage.print();
    cout << endl;
    return 0;
}
