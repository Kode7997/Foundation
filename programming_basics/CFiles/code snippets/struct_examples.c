#include<stdlib.h>
#include<stdio.h>

typedef struct {

    uint8_t *a;
    int *arr;
}Data;


typedef long long int css_t;

int main(){

    css_t number = 50978245974419845;
    printf("examples of number %lld\n",number);

    int a = 10;
    void *p = &a; // void pointer

    // void pointers cannot be directly dereferenced 
    //printf("void pointer derefernecing %d\n",*p); // error    
    printf("right way to dereference void pointer  %d\n",*(int *)p);


    // Data strucutre
    Data *d; // pointer to a structure
    // Data d; // strucutre itself

    d = malloc(sizeof(Data));
    d->a = malloc(sizeof(uint8_t));
    d->arr = malloc(sizeof(int) * 8);

    d->a = (uint8_t *)10;
    for(int i=0;i<8;i++){
        d->arr[i] = i+1;
    }

    for(int i =0;i<8;i++){
        printf("arr %d\n",d->arr[i]);
    }
    printf("num %d\n",d->a);
    
    
    return 0;
}