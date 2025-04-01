/*
Pure Virtual: It can be used to enforce derived class to implement the function/method rather than base class.
Base class doesn't implement the virtual function.

- use virtual when base implementation is required
- use pure virtual when abstraction is required and enforce derived class to implement the method.

*/
#include<iostream>

class Base {

    public:
        int num1;
        Base(int num){
            num1 = num;
        }

        virtual void pure_virtual_func()=0; // this make the class abstract.

        void display() {
            std::cout<<"num1: "<<num1<<std::endl;
        }
};

class Derived: public Base {
    public:
    Derived(int num): Base(num) {
    }

    void pure_virtual_func() override {
        std::cout<<"implement pure virtual and base num1: "<<num1<<std::endl;
    }
};

int main(){

    Derived d(8);
    d.pure_virtual_func();

    return 0;
}
