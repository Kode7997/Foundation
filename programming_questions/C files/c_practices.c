#include <stdio.h>
#include <stdlib.h>


/*
1. typedef - is used for declaration of structure
2. preprocessors
*/

#define BUFFER_LEN 5

struct Array1 {
    int size;
};


struct Array {
    int arr[BUFFER_LEN];
};


struct BufferT {
  int buffer[ BUFFER_LEN ];
  int c;
  int index; //why last ele in struct, value is 1?
};

void preprocessors_check(){

  struct BufferT bufferObj;
  int *buffer = bufferObj.buffer;
  int *index = &bufferObj.index;
  int *c = &bufferObj.c;
  printf("index before loop: %d\t %x\t c:%d\n", *index, &buffer[BUFFER_LEN], *c);
  
  int d =0;
  for ( *index = 0; *index <= BUFFER_LEN; *index = *index + 1 ) { // here when buffer is full, access the buffer[buffer_len] and over writes the memory. that is why index is set to 1 again
    printf("index: %d\t %x\n",*index, &buffer[*index]); 
    buffer[ *index ] = 0;

    if (d == 10){
        break;
    }
    d += 1;

  }
  printf( "Buffer initialized to %d\n", buffer[0] );
  
}

int main() {

    // 1. struct understanding
    // struct Array1 *arr;
    // arr.size = 10;
    //printf("array size: %d\n", arr.size);
    // arr = (struct Array1*)malloc(sizeof(struct Array1));
    // arr->size = 10;
    // printf("array size: %d\n", arr->size);

    //2. prepricessor understanding
    preprocessors_check();

    
    return 0;
}