#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a,b) (a>b)?a:b

int main(){

    char *str = "a man in power";
    printf("str: %s\n", str);

    printf("len of str: %d\n",strlen(str));
    char *name = "man";
    char *result = strstr(str, name);

    
    if (result != NULL){
        printf("yes\n");
        int index = (result - str); // pointer subtraction
        int len = strlen(name);
        char *trimed_str = (char *)malloc(sizeof(char *));
        //trim_string(str,trimed_str, index, len);
        result += strlen(name);
        while (*result == ' ')
        {
            result++;
        }
        
        strcpy(trimed_str, result);


        printf("index is: %ld and trim:%s\n", (result - str), trimed_str);

        //trim - no substr in C

        int a = 3, b = 5;
        printf("max: %d\n",max(a,b));
    }



    return 0;
}