#include <iostream>
#include <string>
using namespace std;

class Tri{
private:
    int line;
    int line2;
public:
    double getArea(string line, string line2){
        this->line = stoi(line);
        this->line2 = stoi(line2);
        return this->line * this->line2 / 2.0;
    }
};

int main()
{
    string line, line2;
    getline(cin, line);
    getline(cin, line2);

   Tri triangle;
   cout << "삼각형의 넓이는 : " << triangle.getArea(line, line2) << endl;

    return 0;
}
