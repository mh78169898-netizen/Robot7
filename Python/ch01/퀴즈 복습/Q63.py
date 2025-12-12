from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def run(self):
        pass

class Taxi(Vehicle):
    def run(self):
        pass
    def __str__(self):
        return '자식 클래스 Taxi'
class Truck(Vehicle):
    def run(self):
        pass
    def __str__(self):
        return '자식 클래스 Truck'
class Bus(Vehicle):
    def run(self):
        pass
    def __str__(self):
        return '자식 클래스 Bus'

vehicle1 = Taxi()
print(vehicle1)
print(vehicle1.run())
vehicle2 = Truck()
print(vehicle2)
print(vehicle2.run())
vehicle3 = Bus()
print(vehicle3)
print(vehicle3.run())
