#include<stdio.h>
#include<stdlib.h>

int main(){

    char *password1 =  malloc(10 *sizeof(char));
    printf("enter the pwd\n");
    scanf("%s",password1);

    char *other_ptr = password1;
    free(password1);

    for(int i=0;i<10;i++){
        printf("%c",other_ptr[i]);
    }
    printf("\n");
    return 0;   
}