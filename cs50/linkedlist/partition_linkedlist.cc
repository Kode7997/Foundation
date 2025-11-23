#include<iostream>
using namespace std;

class Node{
    
    public:
        int key;
        Node *next;
        Node(int key, Node* node): key(key), next(node){}
};


class LinkedList{
    public:

        Node *head;
        Node *tail;

        LinkedList(): head(nullptr), tail(nullptr){}
    
        void push_back(Node* node){
            
            if(head == nullptr){
                head = node;
                tail = head;
            }else{
                tail->next = node;
                tail = node;
            }
            //cout<<"key: "<<node->key<<endl;
        }
        
        void merge(LinkedList* ll){

            if(this->head == nullptr || ll->head == nullptr) return;
            
            this->tail->next = ll->head;
            this->tail = ll->tail;
            ll->head = nullptr;
        }
};


void display(LinkedList *ll){

    
    Node* node = ll->head;
    if(node == nullptr){
        cout<<"head is null"<<endl;
        return;
    }

    while(node != nullptr && (node != ll->tail)) {
        cout<<node->key<<" ";
        node = node->next;
    }

    cout<<ll->tail->key<<endl;
}

void partition(Node* head, int pVal){
    
    LinkedList ls, eq, gr;
    Node* node = head;

    while(node != nullptr){
        if(node->key < pVal){
            ls.push_back(node);
        }else if(node->key == pVal){
            eq.push_back(node);
        }else{
            gr.push_back(node);
        }
        node = node->next;
    }

    // display each list
    // display(&ls);
    // display(&eq);
    // display(&gr);

    
    // merge - assuming lesser list always present.
    ls.merge(&eq);
    ls.merge(&gr);

    // display partition list
    cout<<"output: "<<endl;
    display(&ls);

}

/// @brief linked list 1->3->7->6->4->2
/// @return None

int main() {

    Node n7(2, nullptr);
    Node n6(4, &n7);
    Node n5(6, &n6);
    Node n4(7, &n5);
    Node n3(3, &n4);
    Node n2(1, &n3);
    
    Node* head = &n2;
    Node* tmp = head;

    int pVal; //partition val
    cout<<"Enter partition value"<<endl; // assuming value >0
    cin>>pVal;

    // display linkedlist before partition
    cout<<"Input: "<<endl;
    while(tmp != nullptr) {
        cout<<tmp->key<<" ";
        tmp = tmp->next;
    }
    cout<<endl;

    // partition linkedlist
    partition(head, pVal);

}