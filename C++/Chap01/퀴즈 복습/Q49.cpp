#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    int speed;
    string color;

    Car(const string& brand, int speed, const string& color)
        :brand(brand), speed(speed), color(color){}
public:
    class Builder{
        private:
            string brand = "Kia";
            int speed = 0;
            string color = "Gray";
        public:
            Builder& setBrand(const string& brand){
                this-> brand = brand;
                return *this;
            }
            Builder& setSpeed(int speed){
                this-> speed = speed;
                return *this;
            }
            Builder& setColor(const string& color){
                this-> color = color;
                return *this;
            }
            Car build(){
                return Car(brand, speed, color);
            }
        };
            string getBrand(){
                return brand;
            }
            int getSpeed(){
                return speed;
            }
            string getColor(){
                return color;
            }
};
int main()
{
    Car car = Car::Builder()
                    .setBrand("Kia")
                    .setSpeed(220)
                    .setColor("Gray")
                    .build();

    cout << "Car info\n";
    cout << "Brand: " << car.getBrand() << endl;
    cout << "Speed: " << car.getSpeed() << endl;
    cout << "Color: " << car.getColor() << endl;
    return 0;
}
