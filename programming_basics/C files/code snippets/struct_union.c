#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Union reserves memory based on the largest memeber of the group

if there are multiple members in the group, how do we know which memeber in the group is being used?
to do this, encapsulate union inside the structure as below

*/

typedef struct {
    int type;
    union
    {
        char x[1024];
        int y[1024];
    }buffer;
}Info;


int main(){

    Info info;

    info.type = 0;
    memset(info.buffer.x, 'a', 1024); // sets 'a' character to all 1024 bytes

    if(info.type == 0){
        for(int i= 0;i<1024;i++){
            printf("char x[%d]: %c\n",i, info.buffer.x[i]);
        }
    }

    

    return 0;
}