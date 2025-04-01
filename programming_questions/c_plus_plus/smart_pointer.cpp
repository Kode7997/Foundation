
/*
smart pointer
*/

#include<iostream>
#include<string>
#include<memory>

using namespace std;

class MyClass{

    public:
        int a;
        MyClass(int num) {
            a = num;
            cout<<"constructor"<<endl;
        }

        ~MyClass() {
            cout<<"destructor"<<endl;
        }

        void display(){
            cout<<"my class method"<<endl;
        }
};

// shared pointer

// #include <iostream>
// #include <memory> // For smart pointers

// class MyClass {
// public:
//     MyClass() { std::cout << "MyClass constructor called\n"; }
//     ~MyClass() { std::cout << "MyClass destructor called\n"; }
//     void display() { std::cout << "Displaying MyClass\n"; }
// };

// int main() {
//     std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
//     {
//         std::shared_ptr<MyClass> ptr2 = ptr1; // Shared ownership
//         std::cout << "ptr1 and ptr2 are sharing ownership\n";
//         ptr2->display();
//     } // ptr2 goes out of scope, but memory is not freed because ptr1 still owns it

//     ptr1->display();
//     // Memory will be freed when the last shared_ptr (ptr1) is destroyed

//     return 0;
// }



// weak pointer
// #include <iostream>
// #include <memory>

// class Node {
// public:
//     std::shared_ptr<Node> next; // Shared ownership
//     std::weak_ptr<Node> prev;  // Prevent cyclic dependency <-- weak_ptr
//     ~Node() { std::cout << "Node destroyed\n"; }
// };

// int main() {
//     auto node1 = std::make_shared<Node>();
//     auto node2 = std::make_shared<Node>();

//     node1->next = node2;      // node1 owns node2
//     node2->prev = node1;      // node2 refers to node1 but does not own it

//     // Both nodes will be properly destroyed when the shared_ptrs go out of scope
//     return 0;
// }


int main(){

    int a = 10;

    unique_ptr<MyClass> ptr = make_unique<MyClass>(40);
    ptr->display();


    return 0;
}
