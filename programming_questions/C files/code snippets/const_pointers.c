#include<string.h>
#include<stdio.h>

int main(){

    char *s = "this is literal";    // pointer pointing to literal, we dont know where it is stored in the memory
    printf("index accessing of *s: %c\n",s[2]); // take note of %c here
    // printf("string *s: %s\n", *s); // segmentation fault, why? *s is a pointer to the string but not exactly the string
    // printf("string *s: %s\n", s); // this would print whole string in C
    // char const *s1 = "this is another literal\n";
    //printf("const char: %s\n", *s1); // segmentation fault, why?
    
    // constant pointer
    // char a = 'a';
    // char *const constant_pointer = &a; // this address cannot be changes once address is assigned but value 'a' can be changed by dereferencing
    // printf("constant pointer: %c\n",*constant_pointer);
    // *constant_pointer = 'x';
    // printf("constant pointer: %c\n",*constant_pointer);

    // pointer to a constant - cannot change the reference value it is pointing to. It's reference can be changed to another var reference.
    char b = 'b';
    char const *constant_to_pointer = &b; // pointer cannot change the value it is pointing to but pointer can be used to reference to another memory 
    printf("constant to pointer: %c\n", *constant_to_pointer);
    // // *constant_to_pointer = 'y'; // error bcz its pointer to a constant, where it cannot change the value of the reference it is pointing to.

    // char c = 'c';
    // constant_to_pointer = &c;
    // printf("constant to pointer: %c\n", *constant_to_pointer); 

    // // char array is different from char pointer, can be sliced and be modified. it depends how we declare the string in C
    // char c_arr[] = "this is char array";
    // c_arr[0] = 'x';
    // printf("char arr: %s",c_arr);


    return 0;
}