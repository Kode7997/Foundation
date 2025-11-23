#include<iostream>
#include<string>

using namespace std;

class Base{

    public:
        int number;
        Base(){
            cout<<"defautl base constructor"<<endl;
        }
        Base(int num): number(num){

            cout<<"base constructor"<<endl;            
        }

        virtual ~Base() {
            cout<<"base destructor"<<endl;
        }

        void virtual print(){
            cout<<"base print"<<endl;
        }

        Base(const Base& b){
            cout<<"base copy constructor"<<endl;
            number = b.number;
        }

        void operator=(const Base& b){
            cout<<"oper overload"<<endl;
            number = b.number;
        }
};

class Derived: public Base{
    public:
        Derived()
        {cout<<"default derived constructor"<<endl;}

        Derived(int x):Base(x){
            cout<<"derived constructor"<<endl;
        }

        ~Derived(){
            cout<<"derived destructor"<<endl;
        }

        void print() override {
            cout<<"derived print"<<endl;
        }
};

int main(){
    // Base *b1 = new Base(10);
    // Base *b2 = new Base(*b1); // copy constructor called with new obj
    // delete b1;
    // delete b2;

    // Base b1(10);
    // Base b2 = b1; // copy const
    // Base b3;
    // b3 = b1;

    // Derived *d = new Derived();
    // d->print1();
    // delete d;

    Base *b1 = new Derived();
    b1->print();
    delete b1;
    


}