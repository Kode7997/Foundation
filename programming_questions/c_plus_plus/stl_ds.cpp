#include<iostream>

using namespace std;


#include<vector>
#include<list>
#include<string>
#include<queue>



void vector_func(){
    
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // vector methods
    int len = cars.size();
    string at_0 = cars.at(0);
    string at_1 = cars[1];

    //update
    cars.at(0) = "ferrari";
    cars[0] = "hyundai";

    //add element
    cars.push_back("honda");

    //remove element
    cars.pop_back();


    //auto it = std::find(vec.begin(), vec.end(), element_to_find);

    // front and back. There is no push front or push back in the vectors.
    cout << "cars front: "<<cars.front() << endl;
    cout << "cars back: "<<cars.back() << endl;
    //check empty
    cars.empty();   // returns 1 if empty else 0

    // loop through vector
    for (string str: cars) {
        cout << str << endl;
    }

    // to delete in the middle or range
    // cars.erase(cars.begin()+1); // deletes second ele
    cars.erase(cars.begin()+1, cars.begin()+2); //range

    for(int i=0;i<cars.size();i++) {
        cout << cars[i]<< endl;
    }


    // using iterators
    vector<string>::iterator it;
    for(it = cars.begin(); it != cars.end();it++) {
        cout<< "car: "<< *it << endl;
    }


    // reverse order
    cout << "In reverse order: "<< ends;
    for(auto iter = cars.rbegin(); iter != cars.rend(); iter++ ){
        cout << *iter << "\t";
    }
}  
    

void list_func() {

    /*
    -> two major differences between lists and vectors are:
    -> You can add and remove elements from both the beginning and at the end of a list, while vectors are generally optimized for adding and removing at the end.
    -> Unlike vectors, a list does not support random access, meaning you cannot directly jump to a specific index, or access elements by index numbers.
    -> list is a double linkedlist in c++
    */

    list<string> lst;

    lst.push_front("keshav");
    lst.push_back("raj");
    lst.push_back("maharaj");
    lst.push_front("news of the world");

    list<string>::iterator it;

    cout << "lst elements\n";
    for(it=lst.begin(); it != lst.end(); it++) {
        cout<< *it<< endl;
    }
    
    advance(it, 2); //advance iterator by 2 elements
    lst.erase(it); // then erase
    // lst.clear(); // clear entire list

    // following code throws error. list doesn't support random access
    // for(int i=0;i < lst.size(); i++) {
    //     cout << lst[i] << endl;
    // }

    return;
}


void stack_func(vector<string>& arr){

    arr[0] = "name change";
    
    stack<string> stk;
    stk.push("hello");
    stk.push("world");
    stk.push("India");

    cout << "top: "<< stk.top() << endl;
    stk.pop();
    cout << "empty?: "<< stk.empty() << "\n"; // this func is common for all ds types
    cout << "size: " << stk.size() << "\n"; // this func is common for all ds types

}


void queue_func() {

    queue<string> q;

    q.push("India");
    q.push("Japan");
    q.push("USA");
    q.push("Australia");
    q.push("UK");

    cout << "q front: " << q.front() << endl;
    cout  << "q back: " << q.back() << endl; //top or seek
    cout << "q top: "<<q.back()<<endl;
    cout << "q elements" << endl;
    
    while(!q.empty()) {                  
        cout << q.front() << endl;
        q.pop();
    }


}

void dequeue_func(){
    //A deque (stands for double-ended queue) however, is more flexible, as elements can be added and removed 
    // from both ends (at the front and the back). You can also access elements by index numbers.

    #include<deque>

    deque<string> dq;

    dq.push_back("India");
    dq.push_front("US");
    dq.push_front("srilanka");
    dq.push_front("vietnam");

    cout << "front: "<< dq.front() << endl;
    cout  << "back: "<< dq.back() << endl;

    cout << dq[0] << " " << dq[1] << endl; // elements can be accessed
    
    dq.pop_back();
    dq.pop_front();

    for(auto it = dq.rbegin(); it != dq.rend(); it++){
        cout << *it << " ";
    }

    }


#include <set>
void set_func(){
    /*
    Are sorted automatically in ascending order.
    Are unique, meaning equal or duplicate values are ignored.
    Can be added or removed, but the value of an existing element cannot be changed.
    Cannot be accessed by index numbers, because the order is based on sorting and not indexing.
    */

    set<int> s = {6,5,3,2,1,0};
    s.insert(100);

    for (int i : s){
        cout << i << " ";
    }

    s.erase(100);
    for (int i : s){
        cout << i << " ";
    }

    cout << s.empty() << endl;
    return;

}   

#include <map>
void map_func(){

    map<int, string> people;
    
    people = {{1,"keshav"}, {2, "unknown"}, {3, "anonymous"}};

    people.insert({4,"junk"});

    people.erase(1);

    //map<int, string>:: iterator *it;

    for(auto it = people.begin(); it != people.end(); it++) {

        cout << (it->first) << " is " << (it->second) << endl;
    }

}


int main() {
    vector<string> varr = {"keshav"};
    // vector_func();
    // list_func();
    // stack_func(varr);

    // cout << "changed the name of the array\n";
    // for(auto it=varr.begin(); it!=varr.end();it++){
    //     cout << *it << endl;
    //   }

    queue_func();

    // dequeue_func();

    // set_func();
    // map_func();
}   


/*
common methods in std lib
vector, list(double linkedlist), map, queue, dequeu, stack

1. ds.find(key) != ds.end() //check for value. if equal then no ele found else found. 
    if string, string.find(char) == npos; returns the position if found else -1
    clear => string.clear()
2. ds.begin(), ds.end(), ds.rbegin(), ds.end() //start and end
3. ds.earse(key)
4. ds.empty()
5. vector<string>::iterator *it; or auto it = ds.begin()
6. push => ds.push_back(ele), ds.push_front(ele), ds.push()
7. pop => ds.pop_back(), ds.pop_front(), ds.pop()
8. map.first, map.second


list ds - it's a double linked list
advance iterator by 2? then advance(iterator, 3);
auto it = find(myList.begin(), myList.end(), elementToFind);
if (it != myList.end()) {

set ds:
set.insert(ele)

pair ds:
pair<int,int> pr; p
*/