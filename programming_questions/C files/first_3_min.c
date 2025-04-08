#include<stdio.h>
#include<stdlib.h>


int main(){

    int arr[] = {8, 1, 10, 5, 4, 12};
    int min1 = INT32_MAX;
    int min2 = min1;
    int min3 = min2;
    int i1, i2, i3;

    for(int i=0; i<6; i++) {
        if((arr[i] < min1) && (min1 == INT32_MAX)) {
            min1 = arr[i];
            i1 = i;
            continue;
        } else if((arr[i] > min1) && (arr[i] < min2) && (min3 == INT32_MAX)){
            min2 = arr[i];
            i2 = i;
            continue;
        } else if((arr[i] > min1) && (arr[i] > min2) && (arr[i] < min3) && ((min3 == INT32_MAX))) {
            min3 = arr[i];
            i3 = i;
            break;
        }
    }

    printf("min: %d, %d, %d\n", min1, min2, min3);
    printf("index %d, %d, %d\n", i1, i2, i3);
}