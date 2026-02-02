#include <stdio.h>
/*
use case:
1. to check the different data types
2. embedded systems: when memory is limited.

*/

union item
{
    int x;
    float y;
    char ch;
};

union uni{
    float i;
    int x;
};

int main( )
{
    union item it;
    it.x = 12;
    it.y = 20.2;
    it.ch = 'a';
    

    printf("%d\n", it.x);
    printf("%f\n", it.y);
    printf("%c\n", it.ch);

    //access more than one item in union is not allowed
    printf("x: %d, y: %f c:%c\n", it.x, it.y, it.ch);
    
    // concept of floating point number
    union uni u;
    u.i = 1.0;
    printf("i: %f x: %d\n",u.i, u.x);
    u.x += 1 << 23;
    printf("i: %f x: %d\n",u.i, u.x);
    

    return 0;
}