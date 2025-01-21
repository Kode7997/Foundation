
#include<stdio.h>
#include<stdlib.h>


struct Q{
    int left;
    int right;
    int *arr;
    unsigned int capacity;
};

enum bool {
    false,
    true
};

struct Q* createQ(int limit) {
    struct Q *q = (struct Q*)malloc(sizeof(struct Q));
    q->left = 0;
    q->right = -1;
    q->capacity = limit;
    q->arr = (int *)malloc(sizeof(int)*limit);

    return q;
}

enum bool isEmpty(struct Q *q) {

    if (q->left == -1 || q->left > q->right) {
        return true;
    }
    return false;
}

enum bool isFull(struct Q *q){

    if ((q->right - q->left) == q->capacity){
        return true;
    }
    return false;
}

void push(struct Q *q, int val) {

    if (isFull(q)) {
        printf("queue is full\n");
        return;
    } else {
        if (q->right == q->capacity){
            q->right = -1;
        }
        q->right++;
        q->arr[q->right] = val;
        printf("added ele: %d\n", val);
    }
}

int pop(struct Q *q) {
    int ele = 0;
    if (isEmpty(q)) {
        printf("no elements in the stack\n");
        return 0;
    } else {
        
        ele = q->arr[q->left];
        q->left++;
    }

    return ele;
}

void display(struct Q *q) {
    int l;

    if (q->left == -1) {
        l = 0;
    }
    int r = q->right;
    printf("Display elements: \n");

    while (l<=r)
    {
        printf("%d ",q->arr[l]);
        l++;
    }
    
}

int main() {
    //struct Q *q = (struct Q*)malloc(sizeof(struct Q));
    struct Q *q = createQ(10);
    push(q, 1);
    //printf(" l: %d r: %d",q->left, q->right);
    
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);
    push(q, 6);
    push(q, 7);
    push(q, 8);
    push(q, 9);
    push(q, 10);
    display(q);
    push(q, 11);
    printf("popped ele %d\n",pop(q));
    display(q);

    


    return 0;
}