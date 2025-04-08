#include<iostream>

/*
Diamond Problem ->  diamond shape

            Base
        /           \
    DerivedA      DerivedB
        \           /
            Child
*/

// final keyword: prevent further inheritance

class Base {
    public:
    Base(){

    }

    virtual void print() {
        std::cout<<"base method\n"<<std::endl;
    }
};


class DerivedA : virtual public Base {
    public:
    DerivedA(){
        
    }

    void print() override {
        std::cout<<"derived A"<<std::endl;
    }
};

class DerivedB : virtual public Base {
    public:
    DerivedB(){

    }

    void print() override {
        std::cout<<"derived B"<<std::endl;
    }
};

class MyClass: public DerivedA, public DerivedB{
    public:
    MyClass(){

    }
    void print() {
        std::cout<<"derived MyClass"<<std::endl;
    }
    
};

int main(){

    MyClass mc;
    mc.print();

}