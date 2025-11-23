#include<stdio.h>
#include<stdlib.h>

/*
concepts:

1. char, char array, strings, string pointers, array with strings, memory allocation(malloc, calloc, re-alloc)
2. integer, float, double, long; overflow and underflow
3. pointers, double pointers, array of pointers, pointer array
4. structure, Unions
5. Socket connection programming, IPC, producer consumer problem
6. implement stack using Q; stack and Queue
7. Memory allocation and deallocation

#Utility:
1. sizeOf
*/

int main() {

    int *p;
    char c = 'a';
    char ch[] = {'a','b'};
    int size = sizeof(ch)/sizeof(ch[0]);
    int a = 10;
    p = &a;

    printf("%d\n",*p);
    printf("%c\n",c);
    printf("%d\n",(&ch[0]));
    printf("%d\n",(&ch[1]));
    printf("%d, %d\n", sizeof(int), sizeof(ch));
    printf("sizeof ch: %d",size);
    
    
    return 0;
}