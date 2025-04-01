/*
shallow copy(keeps the reference to the object) vs deep copy (maintains new memory of copy)
*/

#include <iostream>
#include <sstream>
using namespace std;

class Number {

  private:
    int number;
  
  public:

    Number(int number): number(number) {
      cout<<"number constructor called\n";
    }

    Number(const Number& otherNumber) {
      number = otherNumber.number;
    }

    int get() {
      return number;
    }

    void set(int num){
      this->number = num;
      return;
    }

    ~Number(){
      cout<<"destructor is called"<<endl;
    }

};

int main(){

  Number num1(20);
  cout<<"num1: "<<num1.get()<<endl;
  
  Number num2 = num1; // this copy constructor does a deep copy of object and not shallow copy
  cout<<"num2: "<<num2.get()<<endl;

  num1.set(10);
  cout<<"num1: "<<num1.get()<<endl;
  cout<<"num2: "<<num2.get()<<endl;


  // what if new is used 
    // Number *num1 = new Number(10);
    // cout<<"num1: "<<num1->get()<<endl;

    // Number *num2 = num1;                // shallow copy
    // cout<<"num2: "<<num2->get()<<endl;

    // num1->set(20);  
    // cout<<"num1: "<<num1->get()<<endl;
    // cout<<"num2: "<<num2->get()<<endl;

  return 0;
}