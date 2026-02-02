#include<stdio.h>
#include<stdlib.h>

typedef enum bool
{
    flase,
    true

}type_bool;

struct node
{
    int data;
    struct node *next;
};

struct item{
    char *str;
    int *num;
}itm;

struct dp{
    struct itm **it;
    int *val;
}dp;

type_bool compare(void *a, void *b) {

    if (*(int *)a == *(int *)b) {
        return true;
    } else {
        return flase;
    }
}




int main() {

    // int a = 8;
    // int *c;
    // c = &a;
    // printf("\n%d\n",*c);
    // int a[10];
    // printf("a %x",a);
    //printf("a %x",a++);

    // int x = 5, y = 7;
    // int *p = &x;
    // int *q = &y;
    // printf("p is %d\nq is %d\np - q is %d\n", p, q, (p - q));

    int a[10] = {1,2,3,4};

    struct dp *doublePtr;


    printf("%d\n",a);

    int x = 5;
    int y = 4;

    int isEqual = compare(&x, &y);
    printf("x and y are equal: %d",isEqual);

    printf("sizeof %d\n",sizeof(struct node));

    //printf("size of s: %zu\n",sizeof(struct s));
    
}