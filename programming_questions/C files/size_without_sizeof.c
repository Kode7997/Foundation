#include<stdio.h>

struct A{
    int a; 
    double b; 
    char c[10];
};

int main(){

    struct A arr[2];

    //int *p = a;

    printf("%ld\n",(&arr[1]-&arr[0]));


    return 0;
}