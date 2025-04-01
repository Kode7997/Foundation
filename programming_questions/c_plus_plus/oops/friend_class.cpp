#include<iostream>

class Base{

    private:
        int num1;

        void prv_method(){
            std::cout<<"Base private method\n";
        }
        public:
            Base(int num): num1(num){}
        
        
        friend class Derived; // make derived class as friend of base
};
/*
    - Violates the inheritance properties
    - Tightly coupled
*/
class Derived{

    public:

        Derived(){}

        void call_base_private_func(Base& b){
            b.prv_method();
            std::cout<<"Base private number: "<<b.num1<<std::endl;
        }
};

int main(){

    Base b(10);
    Derived d;

    d.call_base_private_func(b);


    return 0;
}