#include <iostream>
#include <cstring>
using namespace std;

class Preson{
    char* name;
    int id;
public:
    Preson(int id, const char* name);
    ~Preson();
    void changeName(const char* name);
    void show(){
        cout << id << ', ' << name << endl;
    }
};
Preson::Preson(int id, const char* name)
{
    this->id = id;
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}
Preson::~Preson(){
    if(name){
        delete[] name;
    }
}
void Preson::changeName(const char* name){
    if(strlen(name) > strlen(this->name)){
        return;
    }
    strcpy(this->name, name);
}

int main()
{
    Preson father(1, "Kitae");
    Preson daughter(father);

    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();
    daughter.show();

    daughter.changeName("Grace");
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();
    daughter.show();
    return 0;
}
