#include<iostream>

using namespace std;

int main() {

    int a = 10;
    
    int &b = a; // here is b is a reference variable for a also called alias for a

     //increment b also increments a and vice-versa
    b++;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    //increment a also increments b and vice-versa
    a++;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}