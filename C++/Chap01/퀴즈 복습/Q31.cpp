1.
#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
   Point(){
    x = 0;
    y = 0;
   }
   Point(int x, int y){
    x = x;
    y = y;
      cout << "x : " << x << "y : " << y << endl;
   }
};

int main()
{
    Point point(10,11);

    return 0;
}

2.
#include <iostream>
using namespace std;

class Point{
private:
    int x, y;
public:
   Point();
   Point(int a, int b);
   void show() {cout << "(" << x << ", " << y << ")" << endl;}
};
Point::Point(){x = 0; y = 0;}
Point::Point(int a, int b)
    :x(a),y(b){}

int main()
{
    Point origin;
    Point target(10,20);
    origin.show();
    target.show();

    return 0;
}
    
