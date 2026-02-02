#include<iostream>

class Parent1{
    public:
    Parent1(){

    }

    void print(){
        std::cout<<"Parent1"<<std::endl;
    }
};

class Parent2{
    public:
    Parent2(){

    }

    void print(){
        std::cout<<"Parent2"<<std::endl;
    }
};


class Child : public Parent1, public Parent2 {
    public:
    Child(){

    }
};


int main() {


    Child c;    
    // c.print(); this causes the ambuguity in function for child object. to solve, provide the type
    c.Parent2::print();
    c.Parent1::print();


    return 0;
}