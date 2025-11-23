#include<stdio.h>
#include<stdlib.h>


struct dll
{
    int data;
    struct dll* next;
    struct dll* prev;
};

struct dll *head = NULL;

void insertNode(struct dll* node, int data) {

    struct dll *newNode = (struct dll*)malloc(sizeof(struct dll));
    newNode->data = data;
   
    if (head == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    } else {
        //insert at begining
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
    
    return;
}

void insertNodeAtEnd(struct dll* node, int data) {

    struct dll* newNode = (struct dll*)malloc(sizeof(struct dll));
    newNode->data =  data;

    struct dll* n = head;

    while (n->next != NULL)
    {
        n = n->next;
    }
    
    n->next = newNode;
    newNode->next = NULL;
    newNode->prev = n;

}

void deletionNode(int data) {

    struct  dll* node = head;
    while (node->data != data) {
        node = node->next;
    }
    if (node->next != NULL) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    }
}

void printdll() {

    struct dll *node;
    node = head;
    while (node != NULL) {
        printf("->%d",node->data);
        node = node->next;
    }
    printf("\n");
}


int main(){

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    printdll();
    insertNodeAtEnd(head,5);
    printdll();
    deletionNode(3);
    printdll();

    return 0;

}