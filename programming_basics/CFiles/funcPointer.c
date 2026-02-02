#include<stdlib.h>
#include<stdio.h>

/**
following program demonstrates 
the application of function of function pointer in details

reference: https://www.geeksforgeeks.org/function-pointer-in-c/

Note:
1) Unlike normal pointers, a function pointer points to code, not data. 
    Typically a function pointer stores the start of executable code.

2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

3) A function’s name can also be used to get functions’ address.

4) can be used in place of switch functionality

5) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.
**/

void func(int a){
    printf("func is called using function pointer: %d\n",a);
}

void add(int a, int b){
    printf("add");
}

void sub(int a, int b){
    printf("sub");
}

void mul(int a, int b){
    printf("mul");
}

int main() {

    //function call using function pointer
    int a = 10;
    int c = 11;

    void (*fun_ptr_arr[])(int, int) = { add, sub, mul};
    void (*func_ptr) (int) = &func;
    (*func_ptr)(10);

    int b;
    scanf("\n%d",&b);

    //function pointer in place of switch case
    if (b<=2 && b>=0) {
        (*fun_ptr_arr[b])(10, 11);
    }

    return 0;
}