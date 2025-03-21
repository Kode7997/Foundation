#include<iostream>
#include<string>

using namespace std;
class Parent {

    public:
        int d;
        virtual ~Parent(){ // without virtual only the base destructor is called. but with virtaul, derived destructor is called making sure proper cleanup
            cout<<"Parent destructor is called\n";
        }
};

class Child : public Parent {

    public:
        int c = 10;
        ~Child(){
            cout<<"child destructor is called\n";
        }
};
int main(){

    Parent *p = new Child; // with this declaration, we can access any of the derived class method at runtime
    cout<<"child value: "<<p->d<<endl;

    delete p; // with virtual, first child destructor followed by base destructors

    return 0;
}

/*
concept if pure virtual functions
class A{
 public:
    virtual ~base() = 0;
};
// defined outside the class
A::~Base(){
cout<<"destructor";
}

*/