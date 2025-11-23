// Doubly Linked List for real-time event queue
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node *head, *tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void push_back(int data) {
        Node* node = new Node(data);
        if (!tail) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }
    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.print();
    dll.pop_front();
    dll.print();
    return 0;
}
