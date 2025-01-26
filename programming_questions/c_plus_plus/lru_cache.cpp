/*
LRU-cache - unordered_map with double lineked list
unordered_map<int, Node>
*/

#include<iostream>
#include<sstream>
#include<unordered_map>

using namespace std;


class Node{
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int key, int value):key(key), value(value), next(nullptr), prev(nullptr){}
};


class LRUC{
    private:
        int capacity;
        unordered_map<int, Node*> cache;
        Node *head;
        Node *tail;

    
        void remove(Node* node){
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            if(node == head) head = node->next;
            if(node == tail) tail = node->prev;
        }

        void add_to_front(Node* node){
            node->next = head;
            node->prev = nullptr;
            if(head) head->prev = node;
            head = node;
            if(!tail) tail = node;
        }

    public:

        LRUC(int cap) {
            capacity = cap;
            head = nullptr;
            tail = nullptr;
        }

        //get
        int get(int key){
            if(cache.find(key) == cache.end()) return -1;

            Node *node = cache[key];
            remove(node);
            add_to_front(node);
            return node->value;
        }

        //put
        void put(int key, int value){
            if(cache.find(key) != cache.end()) {
                Node* node = cache[key];
                remove(node);
                node->value = value;
                add_to_front(node);
            } else {
                if (cache.size() == capacity) {
                    cache.erase(tail->key);
                    remove(tail);
                }
                Node* node = new Node(key,value);
                add_to_front(node);
                cache[key] = node;
            }
        }


};

int main() {

    LRUC cache(5);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    cache.put(5, 5);

    cout << cache.get(1) << std::endl; // returns 1
    cache.put(6, 6); // evicts key 2
    cout << cache.get(2) << std::endl; // returns -1 (not found)
    cache.put(7, 7); // evicts key 3
    cout << cache.get(3) << std::endl; // returns -1 (not found)
    cout << cache.get(4) << std::endl; // returns 4
    cout << cache.get(5) << std::endl; // returns 5
    cout << cache.get(6) << std::endl; // returns 6
    cout << cache.get(7) << std::endl; // returns 7
}