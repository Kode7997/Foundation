/*
shallow copy(keeps the reference to the object) vs deep copy (maintains new memory of copy)
*/

#include <iostream>
#include <sstream>
using namespace std;

class Add {
public:
  int num1;
  Add(int num1) 
  { 
      this->num1 = num1; 
    }

 Add(const Add& obj){
     this->num1 = obj.num1;
 }

  int operator+(Add &obj) {
    cout << "Add overloader is called\n";
    return num1 + obj.num1 + 100;
  }

  bool operator==(Add &obj) {
    cout << "is equal?\n";
    return num1 == obj.num1;
  }
};

int main() {

  stringstream ss("Hello world!, I am a string stream");
  string s;

  while (ss >> s) {
    cout << s << endl;
  }

  // operator overloading
  Add a = Add(10);
  Add b = Add(20);

  cout << a + b;
  cout << (a == b);

  Add c = b; // copy constructor is called
  // this will fail because compiler considers it as assignment operator. to avoid, initialise when declared. only then copy constructor is called.
  // Add c;
  // c = b;
  cout << c.num1;
}