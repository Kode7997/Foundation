import random

class Parent:

    def __init__(self, car = None):
        self.car = car()
    
    def get_car_price(self):
        
        print(f'four wheler {self.car()} and its price {self.car().price()}')
    

class A:

    def price(self):
        return 10000
    
    def __str__(self):
        return "creta"

class B:
    
    def price(self):
        return 10
    
    def __str__(self):
        return "s-cross"

def choose_random_car():
    return random.choice([A,B])

if __name__ == '__main__':

    #a = A()
    #print(f'name of car {a} and price{a.price()}')
    car = Parent(choose_random_car)
    car.get_car_price()

