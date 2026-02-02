#include<iostream>
#include<string>

/*
reference = https://github.com/tazbin/object-oriented-programming-OOP/tree/66763b285f91d00e3d5ae1a61726128b55045e27
*/



using namespace std;

class Parent {

    public:
        int d;
        ~Parent(){
            cout<<"destructor is called\n";
        }
};

int main(){

    Parent p;
    p.d = 10;
    cout<<"parent number: "<<p.d<<endl;

    return 0;
}

/*
by default destructor is called after parent object is out of scope;
*/