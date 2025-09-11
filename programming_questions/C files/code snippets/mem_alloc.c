#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ALIGN[16];

union header {
    struct {
        size_t size; // 8 bytes bslly unsigned long int
        unsigned int isfree; // 4 bytes
        union header *next; // 8 bytes
    }s;
    ALIGN stub; // 16 bytes
};

typedef union header *header_t;


void put_data(int *p){
    printf("address in *p %d\n",*p);

    *p = *p | 3;
    return;
}

unsigned int get_data(unsigned int p){

    return (p & 3);
}

void clean_pointer(int *p){
    *p &= ~3;                   // encrypt pointer
}

int main(){

    size_t size = sizeof(union header);
    printf("%zu\n", size);
    
    // unsigned int x=6;
    // unsigned int p = (unsigned int)&x;

    // printf("before put data, p address %d\n", p);
    // put_data(&p);
    // printf("after put data, p address %d\n", p);
    // printf("after put data, x address %d\n", &x);

    // printf("after put, get value of p %d\n", get_data(p));
    // clean_pointer(&p);
    // printf("after clean data, x address %d\n", p);
    // printf("after clean data, x address %u\n", *(int *)p);

    return 0;
}