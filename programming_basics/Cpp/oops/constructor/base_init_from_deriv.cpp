#include <iostream>
using namespace std;

class Base {
protected:
    int value;

public:
    Base(int v) : value(v) { // Base class constructor
        cout << "Base class constructor called, value = " << value << endl;
    }
};

class Derived : public Base {
private:
    int derivedValue;

public:
    Derived(int baseValue, int derivedValue) : Base(baseValue), derivedValue(derivedValue) { // Base constructor is explicitly called
        cout << "Derived class constructor called, derivedValue = " << derivedValue << endl;
    }
};

int main() {
    Derived obj(10, 20); // Creating an object of the derived class
    return 0;
}
