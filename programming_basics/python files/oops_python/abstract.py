from abc import ABC, abstractmethod

class AbstCls(ABC):

    @abstractmethod
    def name(self):
        pass

class Emp(AbstCls):

    # def __init__(self):
    #     self.name = "keshav"
    
    def name(self):
        print("abs methods")
    
    # def foo(self):
    #     print("methods")


if __name__ == '__main__':

    ob = Emp()
    # obj.foo()
    ob.name()