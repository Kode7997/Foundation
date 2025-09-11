/*
min heap

parent = (i-1)/2
left = 2*i + 1
right = 2*i + 2

min heap:
    insert: heapify_up
    delete: heapify_down
*/

#include<stdio.h>
#include<stdlib.h>


struct heap {
    int *arr;
    int size;
    int left;
};

struct heap* create_heap(int size) {
    struct heap* hp = (struct heap *)malloc(sizeof(struct heap));
    hp->arr = (int *)malloc(size * sizeof(int));
    hp->size = size;
    hp->left = 0;

    return hp;
}

void heapify_up(struct heap* hp, int i) {

    while (i != 0 && (hp->arr[(i-1)/2]) > (hp->arr[i]))
    {
        //swap values
        int temp = hp->arr[(i-1)/2];
        hp->arr[(i-1)/2] = hp->arr[i];
        hp->arr[i] = temp;

        i = (i-1)/2;
    }
    
}

void heapify_down(struct heap* hp, int i){
    int smallest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if (left<hp->left && hp->arr[left]<hp->arr[smallest]){
        smallest = left;
    }

    if (right<hp->left && hp->arr[right]<hp->arr[smallest]){
        smallest = right;
    }

    if (smallest != i) {
        int temp = hp->arr[i];
        hp->arr[i] = hp->arr[smallest];
        hp->arr[smallest] = temp;
        heapify_down(hp, smallest);
    }
}


void delete_heap(struct heap *hp) {

    if (hp->left != 0){
        int last_ele = hp->arr[hp->left-1];
        hp->left--;
        hp->arr[0] = last_ele;
        heapify_down(hp, 0);
    }else{
        printf("No elements in the heap\n");
    }
    
}

void insert_heap(struct heap* hp, int ele){

    if (hp->left < hp->size){
        hp->arr[hp->left] = ele;
        hp->left++;
        heapify_up(hp, hp->left-1);
    }else{
        printf("heap is full\n");
    }
    
    return;
}


void display(struct heap *hp){
    printf("\n");
    for (int i=0;i<hp->left; i++){
        printf("ele: %d\t",hp->arr[i]);
    }
}




int main(){
 
    //create heap structure
    struct heap* hp = create_heap(4);

    // add element to the end of the list
    insert_heap(hp, 10);
    insert_heap(hp, 9);
    insert_heap(hp, 8);
    insert_heap(hp, 1);
    insert_heap(hp, 2);
    display(hp);
    delete_heap(hp);
    display(hp);

    free(hp->arr);
    free(hp);

    return 0;

}

