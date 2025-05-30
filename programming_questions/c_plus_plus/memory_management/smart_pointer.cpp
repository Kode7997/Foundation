
/*
smart pointers:
    // used to grant type of ownership (exclusive, shared)
1. unique_ptr<class_type> make_unique<class_type>(),move()
2. shared_ptr<class_type> make_shared<class_type>()

Shared Ownership and Reference Count:
A shared_ptr manages the lifetime of an object through **reference counting**. Each time a shared_ptr is created or copied, 
the reference count is incremented. When a shared_ptr is destroyed, the reference count is decremented.
The object is only destroyed when the reference count drops to zero.

Cyclic References:
In a cyclic dependency, two objects hold shared_ptr references to each other. This creates a strong ownership loop, 
where neither object's reference count can reach zero because each object's **reference count depends on the other**.

3. weak_ptr<class_type>
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
// ** concept of reference count in case of cleaning of object.**
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

// Example for shared ptr, why weak ptr is needed when obj is shared with multiple members.

class TeamMember {
public:
    std::weak_ptr<TeamMember> partner;  // ✅ Use weak_ptr to break cyclic dependency
    TeamMember() { std::cout << "TeamMember Created\n"; }
    ~TeamMember() { std::cout << "TeamMember Destroyed\n"; }
};

int main() {
    std::shared_ptr<TeamMember> alice = std::make_shared<TeamMember>();
    std::shared_ptr<TeamMember> bob = std::make_shared<TeamMember>();

    alice->partner = bob;  // Weak reference
    bob->partner = alice;  // Weak reference

    return 0;  // Objects are deleted properly, avoiding memory leaks.
}



int main(){

    int a = 10;

    unique_ptr<MyClass> ptr = make_unique<MyClass>(40); // iternally calls (new MyClass). so whenever there is exception, memory is cleaned properly without leaks.
    ptr->display();


    return 0;
}
