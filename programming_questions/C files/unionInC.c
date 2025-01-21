#include <stdio.h>

union item
{
    int x;
    float y;
    char ch;
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
    //printf("x: %d, y: %f\n", it.x, it.y);
    
    return 0;
}