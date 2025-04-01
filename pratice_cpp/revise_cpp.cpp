#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<typeinfo> // check the ty[e]
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<deque>

using namespace std;

/*

STL => crud operation
vector
list
set
string
unordered_map, ordered_map
stack
queue
deque

smartpointers, unique, shared.
semaphor, mutex, pthread, and omp

bitwise operators
revise OS concepts

*/


template <typename T>
void display(const T& object) {
    cout<<"allowed"<<endl;
    for(auto item: object) {
        cout<<"items: "<<item<<endl;
    }
}

template <typename K>
void display2(const K& object){

    auto it = object.begin();
    while(it != object.end()){
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
        it++;
    }
}

void vector_func() {
    vector<string> v = {"hellow", "world"};

    //crud
    v.push_back("from Cpp");

    // search
    // auto it = find(v.begin(), v.end(), target) and check if(it != v.end())
    if (find(v.begin(), v.end(),"hellow") != v.end()){
        cout<<"element present: "<<endl;
    }

    //delete
    v.erase(v.begin(), v.begin()+1); // erase the first elemet

    //display
    display(v);

    // v.clear(), v.empty()

}

void list_func(){ // its a double linkedlist

    list<string> l = {"jayanagr","ramnagar","jpnagar"};

    l.push_front("abhiram");

    l.push_back("abhiram");
    display(l);
    auto it = l.begin(); // set the iterator

    advance(it, 2); // move the pointer by 2 positions

    l.insert(it, "keshav"); // update

    it = l.begin();
    advance(it,0);
    l.erase(it);

    l.pop_front();
    l.pop_back();

    display(l);
    

}

void set_func(){

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    display(s);
    s.erase(2);
    display(s);
}


void ordered_map_func(){
    map<int, string> mp;

    mp.insert({2,"name"});
    mp.insert({1,"name"});
    mp.insert({0,"name"});

    display2(mp);

    mp.erase(2);

    display2(mp);

    cout<<"is map empty "<<mp.empty()<<endl;
    if (mp.find(1) != mp.end()){            // search
        cout<<"key present\n";
    }
}


void deque_func(){

    deque<string> dq;

    dq.push_back("dsjn");

    display(dq);
}


int main() {

    // vector_func();

    // list_func();

    // set_func();

    // ordered_map_func();
    
    // stack

    // deque
    deque_func();

    return 0;
}