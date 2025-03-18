#include<stdlib.h>
#include<stdio.h>

int main(){

    // 0000 1010
    unsigned int x = 0;

    // why and how complement of 10 is -11
    unsigned int y = ~x;

    printf("val: %d\n",y);
}