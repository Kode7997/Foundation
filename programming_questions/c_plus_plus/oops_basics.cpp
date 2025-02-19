#include<iostream>

using namespace std;

/*
protected variables are not accessible outside the class. Inherited class can use protected variables.
*/
class MyClass {     // class name
    int c;          // private variables.
    public:         // access specifier. if not access specifier, then all variables are private. //public, private, protected.
        int a;      
        int b;
        string word;

        MyClass set_and_get_elemenets() {
            MyClass obj2;
            obj2.a = 100;
            obj2.b = 200;
            obj2.c = 300;
            return obj2;
        }

        MyClass outside_method();   // func declared inside class but defined outside the class

}; // semicolon is mandatory for class

MyClass MyClass::outside_method() {
    MyClass obj4;
    cout<<" method defined outside class using ::"<<endl;

    return obj4;
}


class MyClass2 {

    public:
        int x;
        string y;
        MyClass2(int x, string y) {         // constructor is always public and defined same name as class
            this->x = x;                    // if same names are used as members, then issue of "name shadowing" occurs
                                            // in C++. therefore "this->" keyword is used to point to class members.
            this->y = y;
        }

        void display() {
            cout << x <<" string: "<< y << endl;
        }
};


// encapsulation
class MyClass3 {

    private:
        int prv_var; //encapsulation of data
    
    public:
        int parent_var;
        // use setters and getter to get the encapsulated data instead directly accessing
        void set_data(int i){
            this->prv_var = i;
        }

        virtual ~MyClass3() {        // virtual destructor, first calls the destructor of the derived class and then base class.
                                     // if "virtual" is not provided, then only base class destructor is called.
            cout << "base class destructor" << endl;
        }

        int get_data() {
            return this->prv_var;
        }

        virtual void display() {    // virtual keyword for polymorphism
            cout<<"parent method invoked"<<endl;
        }

};

// inheritance
class MyClass4 : public MyClass3 {

    public:
        int child_var;

        MyClass4(int x, int y) {
            this->parent_var = x;
            this->child_var = y;
        }

        // concept of overriding. here, it's not actually overriding but it is hiding or shadowing. without "virtual/override" keyword
        // compiler call the function based on the type of the pointer but not function to what pointer is referenced to.
        void display() const override { // if derived class method has same name as base class method then derived class method overrides the base class. if
                        // if same method needs to be called using child obj then :: (object resolution) is used. refer parent_invoke method
            cout << "child method"<< endl;
            cout << this->parent_var <<" pub var: "<< this->child_var<<endl;
        }

        void parent_invoke(){
            MyClass3::display();
        }
};

//multi-level inheritance
// code snippet: class MyClass4 : public MyClass3, public MyClass2{};

//polymorphism => "many forms"
// method overriding and method overloading


int main(){

    MyClass obj1;
    obj1.a = 10;
    obj1.b = 20;
    //obj1.c = 30; //error bcz it's private variable.

    MyClass obj3;
    obj3 = obj3.set_and_get_elemenets();
    cout << "obj2 elements: " << obj3.a <<" "<<obj3.b<<" "<<endl;
    obj1.outside_method();

    //constructor
    MyClass2 cls_obj1(1,"keshav");
    cls_obj1.display();


    //encapsulation
    MyClass3 cls3_obj;
    cls3_obj.set_data(10);
    cout << "get cls3 prv_var: " << cls3_obj.get_data() << endl;

    //concept of virtaul destructor
    MyClass3 *baseclass = new MyClass4;
    delete baseclass;   // calls first derived destructor and then base destructor bcz of "virtual" keyword.
                        // if no virtual keyword, then calls only base class because of the type.


    //inheritance
    MyClass4 cls4_obj(400, 500);
    cls4_obj.parent_invoke();
    cls4_obj.display();

    /*
    polymorphism
    -   overriding requires "virtual/override" keywords otherwise it can cause runtime polymorphism issue. without these
        keywords, base func is shadowed.
    -   overloading: Don't need any keywords, which function to be called is decided during runtime based on parameter type passed.

    */
}

