/*
shallow copy(keeps the reference to the object) vs deep copy (maintains new memory of copy)
*/

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Number {
   
  public:
    int *number;
    Number(int num){
        number = (int *)malloc(sizeof(int));

        *number = num;
        cout<<"number mem is: "<<number<<endl;
    }

    Number( Number& otherNumber) {
      *number = *(otherNumber.number);
    }

    int get() {
      return *number;
    }

    void set(int num) {
      *number = num;
    }

    ~Number() {
      cout<<"destructor is called"<<endl;
      free(number);
    }
};

int main() {
    int static_add = 1;
    cout<<"static address: "<<&static_add<<endl;
    //int* heap_add = (int *)malloc(sizeof(int));
    //cout<<"heap address: "<<heap_add<<endl;
    //free(heap_add);

    Number num1(20);
    cout<<"num1: "<<(num1.get())<<endl;
    
    Number num2 = num1; // this calls the default constructor and does a shallow copy.
    cout<<"num2: "<<num2.get()<<endl;
    
    cout<<"address of num1: "<< (num1.number) <<" address of num2: "<< (num2.number) <<endl;
    num1.set(10);
    
    cout<<"num1: "<<num1.get()<<endl;
    cout<<"num2: "<<num2.get()<<endl; // error because it's shallow copy, we are trying to delete already freed memory
    exit(0);  // if this is not present, it throws error, why? 
    // because when a default copy constructor is called, it does a shallow copy, and when destructor deletes the object,
    // it calls free() two times but memory is created only once. to solve this problem, override the default copy constructor 
    // so that both objects will point to different memory locations.
    return 0;
}