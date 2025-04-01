#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{   
    char *password1;
    char *password2;

    password1 = (char *)malloc(7 *sizeof(char)); // 7 bytes of memeory
    password2 = (char *)malloc(7 *sizeof(char)); 

    strcpy(password1, "123456");
    strcpy(password2, "xyz123");

    printf("address1: %p\n",(void *)password1);
    printf("address2: %p\n",(void *)password2);

    char *other_ptr = password2;
    password2 = (char *)realloc(password2, 20 * sizeof(char));

    // for (int i = 0; i < 20; i++) {
    //     printf("password2[%d]: %c (Address: %p)\n", i, password2[i], &password2[i]);
    // }
    for(int i=0;i<20;i++){
        printf("%c",other_ptr[i]);
    }
    
    for(int i=0;i<20;i++){
        printf("%c",password2[i]);
    }

    return 0;
}