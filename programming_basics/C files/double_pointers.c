#include<stdio.h>


int main(){

    int a = 15;
    int *p = &a;
    int **p1 = &p;

    printf("addres of a: %d\t value of a: %d\t address of p: %d\t value of **p1: %d\n", &a, **p1, &p, **p1);


    return 0;
}