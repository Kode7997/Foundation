#include<stdio.h>


 void func1(){
     printf("func1\n");
 }

float multiply(float a, float b){
    return a*b;
}

float add(float a, float b){
    return a+b;
}

void helper_func(float (*mul)(float, float)){
    float res = (*mul)(1.1,2.2);
    printf("fun param: %f\n", res);

    return;
}


int main(){

    void (*pointer_to_func)() = &func1;
    (*pointer_to_func)();

    //pass argument as well
    float (*multiple_func)(float, float) = &multiply;
    float res = (*multiple_func)(1.6, 7.3);
    printf("multple: %f\n",res);

    // function arr
    float (*array[])(float, float) = {multiply, add};
    float sum = (*array[1])(1.1, 2.2);
    printf("sum: %f\n", sum);

    // pass func as parameters
    helper_func(&multiply);

    
    return 0;
}