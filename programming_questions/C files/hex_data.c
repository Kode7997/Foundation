#include<stdio.h>
#include<stdlib.h>



void bitwise_operators(){

    /*
    convert 32bit to 64bit int
    */

    int32_t val = 0x12345678;
    int64_t val2 = (int64_t)val;
    // int64_t val2 = 0;
    // for(int i=1;i<=64;i++) {
    //     val2 = val2 << 1;
    //     val2 = val2 | (val & 1);
    //     val = val >> 1;
    // }
    printf("64bit: 0x%llx type: %zu\n",val2, sizeof(val2));
}

int main() {
    int n = 0x12345678;
    printf("%x\n",n);

    int h = 0xFF;
    int d = 0x0;

    for(int i=0;i<4;i++){
        d = (n >> i * 8) & h; // right shift by 8bits each time and do bitwise and of 0xFF(F: 4bits and F:4bits = 1 byte)
        printf("n: %x\n", d);
    }

    bitwise_operators();
    return 0;
}

