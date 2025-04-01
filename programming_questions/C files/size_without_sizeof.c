#include<stdio.h>
#include<stdlib.h>

struct A{
    int a; 
    double b; 
    char c[10];
    int *p;
};

int main(){

    struct A arr[2];

    //int *p = a;
    printf("size %lu\n",sizeof(struct A));
    printf("%ld\n",(&arr[1]-&arr[0]));

    struct A *ptr;
    ptr = (struct A*)malloc(2 * sizeof(struct A));
    printf("%d\n",(char *)&ptr[1] - (char *)&ptr[0]);
    
    return 0;
}