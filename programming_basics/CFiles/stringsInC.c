#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    //declare a string
    char s[] = "keshav";
    printf("hello\n");
    printf("string is: %s\n",s);
    printf("len of str: %ld\n",strlen(s));

    char d[strlen(s)+1];

    strcpy(d,s);
    printf("copied string is %s\n",d);

    char *t;
    char x[] = "namasthe";

    t = x;
    for(int i=0;i<=strlen(x);i++){
        printf("%c",t[i]);
    }

    if(strcmp(d, s) == 0){
        printf("\n string are equal\n");
    }else{
        printf("strings are not equal\n");
    }

    return 0;
}
