#include<stdio.h>
#include<stdlib.h>

#include<stdarg.h>

#include<string.h>



// void print(int n, ...){

//     // struct for argument list
//     va_list arg;

//     // arg and number of arguments
//     va_start(arg, n);
//     for(int i=0;i<n;i++) {
//         int x = va_arg(arg, int); // argument and type of argument
//         printf(" argumet: %d\n", x);
//     }
//     va_end(arg);

// }

void print(char *p, ...) {

    va_list arg;

    va_start(arg, p);
    for(int i=0;i<strlen(p);i++) {
        if(p[i] == 'd'){
            int x = va_arg(arg, int);
            printf("nums: %d",x);
        }else if( p[i] == 'f'){
            float f = va_arg(arg, double);
            printf("nums: %f ",f);
        }

        printf("\n");
    }
    va_end(arg);
}

int main(){
    
    /*
     - How does printf function accepts variable number of arguments and different type of data?
     - Idea is to use stdarg lib
     - va_list, va_start, va_arg, va_end - using these we can implemet the custom printf or func that can accept var 
        number of arguments
    */

    // print(3,1,5, 9); // fist param is number of arguments passed and followed by list of argumets

    /*
        Instead above, lets say we pass the placeholders as string literal as followed to track the type 
    */

    print("ddddf",3,4,5,6, 3.5);

    return 0;
}