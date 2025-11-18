#include <iostream>
#include <string>

int main()
{
    using namespace std;
    cout << "please enter your first name: ";
    string name;
    cin >> name;
    //출력하는 메세지 구성
    const string greeting = "Hello, " + name + "!";
    //안삿말의 2번째,4번째 행
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";
    //인삿말의 1번째,5번째 행
    const string first(second.size(), '*');
    //출력
    cout << endl;
    cout << first << endl;
    cout << second << endl;
    cout << "* " << greeting << " *" << endl;
    cout << second << endl;
    cout << first << endl;

    return 0;
}
