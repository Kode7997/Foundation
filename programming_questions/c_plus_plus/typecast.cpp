#include<iostream>
#include<typeinfo>

using namespace std;

int main() {

    int x =65;
    double y = (double)x; // still works in cpp like in c

    cout << "cpp double y: " << x + 0.5 << endl;


    //actual typcast in c++
    //static_cast, dynamic_cast, const_cast, reinterpret_cast

    int a = 16;
    double b = static_cast<double>(a);
    cout << "double of a: "<< b << endl;

    /*
    dynamic_cast
    
    class Base {
        virtual void dummy() {} 
    };
    class Derived : public Base {
        int a;
    };
    Base* base = new Derived;
    Derived* derived = dynamic_cast<Derived*>(base);
    */

    const int* p = &x;
    int* q = const_cast<int*>(p); // Removing constness


    int* r = &x;
    char* s = reinterpret_cast<char*>(r); // Unrelated type conversion

    cout << "reinterpret cast "<< *s << endl;

   return 0;

}