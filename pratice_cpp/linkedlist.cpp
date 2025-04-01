#include<iostream>

using namespace std;

class Node {
    public:
        int key;
        Node *next;

        // overrides the default constructor
        Node(int key): key(key), next(nullptr){
            cout<<"constructor is called\n";
        }

        //overrides the default destructor
        ~Node(){
            cout<<"destructor is called\n";
        }
};


void display(Node *head){
    Node *node = head;
    while(node){
        cout<<node->key<<"->";
        node = node->next;
    }
    cout<<"nullptr"<<endl;
    return;
}

int main(){
    Node *head = nullptr;
    Node* tail = nullptr;

    for(int i=0;i<10;i++){
        Node* new_node = new Node(i);
        
        
        if (head == nullptr){
            head = new_node;
            tail = head;
        }else{
            tail->next = new_node;
            tail = new_node;
        }
    }

    display(head);
       
    while(head){
        Node *node = head->next;
        delete head;
        head = node;
    }

    return 0;
}