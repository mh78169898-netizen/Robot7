#include <iostream>
using namespace std;

int main()
{
    cout << "너비를 입력하세요>>";

    int wid;
    cin >> wid;

    cout << "높이를 입력하세요>>";

    int hei;
    cin >> hei;

    int area = wid*hei;
    cout << "면적은 " << area << "\n";
    return 0;
}
