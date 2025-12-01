#include <iostream>
#include <string>
using namespace std;

void msg(int id){
    cout << id << endl;
}

void msg(int id, string s = ""){
    cout << id << ":" << s << endl;
}

int main()
{
    msg(5, "Good Moning");
    msg(6); //디폴트 매개변수 --> 매개 변수를 2개 사용한 것!!!
    return 0;
}

