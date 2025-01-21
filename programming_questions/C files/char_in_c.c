#include<stdio.h>

int main(){
    // There is difference between C and C++ when dealing with the char. In C, characters are promoted to int and 
    // int can be promoted to char but C++ it cannot be done.

    //e.g:
    char letter = 'a';
    int num = letter + 5; //add char type and int 

    printf("num: %d\n",num); // output: 97 + 5 = 102

    int b = 98;
    char let = 'b'; 

    if (b == let){   //char and int are compared
        printf("Yes a and let are equal\n");
    }


    return 0;
}