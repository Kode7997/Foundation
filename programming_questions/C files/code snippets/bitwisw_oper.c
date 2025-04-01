#include<stdlib.h>
#include<stdio.h>

int main(){

    // 0000 1010
    unsigned int x = 0;

    // why and how complement of 10 is -11
    unsigned int y = ~x;

    printf("val: %d\n",y);

    uint8_t a = 1;
    uint8_t b = 2;

    uint8_t c = a | b; // if atleast 1 of the bit is one, then one
    c = a & b;
    c = a ^ b; // bit is set to 1 if corresponding bits in operand are different. 0 if it is same.
    a =  a << 1; // left shift and right shift bits
    c = a ^ b;

    int d = 7;
    // check if perfect square
    if ((d & (d-1) )== 0){
        printf("its is perfect square\n");
    }else{
        printf("not a perfect square\n");
    }

    // swap values using bitwise operator
    int x = 3; 
    int y = 4; 

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("x: %d, y: %d\n",x, y);

    // xor same numbers will be 0. that's how one can find missing number
    
    printf("c: %d\n",c);
}