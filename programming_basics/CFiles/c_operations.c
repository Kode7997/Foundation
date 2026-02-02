#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1. Data Types 
2. I/O: gets and puts, sprintf
3. Scope of variables: 
    extern: global variable that can extend it's scope to another C source file
    static: var available till the process is a live
    volatile: informing the compiler not to optimize this var
4. callback function
5. pointer array and double pointer
6. size of struct and unions
7. In C, global and static variables memory gets allocated in data segment. local variables and func call gets allocated in stack;
    dynamic memory allocation, gets allocated in heap
8. memory leak (occurs when memory is not properly freed), stack-overflow and underflow
9. use of -> and . operator while accessing the structure members
10. string in C, methods used to copy, iterate and modify
11. *(ptr + 0) is same as arr[0]
12. stack size of recursive calls: this size can be controlled using posix thread. usually size is determined based on the OS,
    compiler, hardware arch. pthread_attr_get_stacksize();
*/

struct arr_ele {
    int ele1;
    int ele2;
};

typedef struct arr_ele ae; // this is the instance of the structure


// padding doesn't happen if size is inline with the 4byte boundary. 
struct sizeofstruct { 
    int *arr[10]; // 8 * 10 = 80 bytes // 64bit
    char c;     // allocates 1 byte + 7 bytes (concept of padding -  for better CPU performance; limit the number of memory access, ensuring that data is aligned with memory boundaries)
    char *ch;   // 8 bytes
    float f;    // 4 bytes + 4 bytes(bcz of 64bit machine, allocates nearest boundary which is 8 bytes)
    double d;   // 8 bytes
};

/*
Note:   local variables and structure instances, memory is allocated in the stack and deallocated once it out of scope. 
        dynamic allocation of variables (malloc, calloc) memory gets allocated in HEAP memory and deallocation needs to be handled.
*/

typedef struct sizeofstruct sos;

union sizeofunion {
    int i;
    float f;
    char str[20]; // allocates largest size in the union
};

void sizeof_str_and_union() {
    //size of structure and union
    sos *s;

    // allocate memory to the structure
    s = (sos *)malloc(5 * sizeof(sos));
    printf("size of struc %zu\n",sizeof(struct sizeofstruct));


    // allocated memory for memebers at same location(key difference from structure)
    // size of Union is based on the size of the biggest member from Union family

    union sizeofunion sou; // bteer memory handling esp in embeded systems with limited memoery, and while dealing with different memory types
    sou.i = 10;
    printf("value of union memeber i: %d\n",sou.i);

    sou.f = 9.99;
    printf("value of union member i: %d (which will be garbage value) after assign for another member flaot f: %f\n",sou.i, sou.f);

    strcpy(sou.str, "union str member");
    printf("value of str: %s\n",sou.str);

}


// malloc
void arr_malloc() {

    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));

    int size = sizeof(*arr);
    printf("size of arr: %d\n",size);

    //free memory
    free(arr);
    //arr = NULL; // dangling pointer - It's pointer that tries to acces the memory that is freed or unallocated 
}


// calloc
void mem_calloc(){
    // 2-d array
    int **arr = (int **)calloc(5 , sizeof(int *));
    if (!arr){
        printf("calloc mem not allocated\n");
        return;
    }
    for(int i=0;i<5;i++){
        // alloc mem for column for each row
        arr[i] = (int *)calloc(5, sizeof(int));
    }

    printf("size of 2-d array %lu\n",sizeof(arr));
    
    // free memory
    for(int i=0;i<5;i++) {
        free(arr[i]);
    }
    free(arr);
}



void callback_func() {
    printf("this func is called using callback mechanism\n");
}

// use case: used in event handling. lets say i pass the function as a parameter to the function, only when certain event occurred
// i will call the callback function to perform certain operation.

void caller_of_callback(void (*callback)()) {
    printf("caller of callback\n");
    (*callback)(); // call callback function
}

void assign_and_callback() {               //callback function implementaton
    printf("assign callback\n");
    caller_of_callback(&callback_func);
}

void reverse_string(char str[]){
    //Hello
    int l = strlen(str);
    printf("string: %s and length of the string is %d\n", str, l);

    for (int i =0; i<l/2;i++){
        char temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }

    printf("reversed string %s\n",str);
}

void string_operations() {
    // strstr(return the pointer of first occurence of char or string), strcmp, strtok(), strcat, strcpy

    char str1[20] = "Hello"; // static allocation; mutable (can be modified)
    char str2[] = "world"; // size is determined automatically
    char *str = "Helo"; // immutable (bcz it is decalred as pointers, cannot be modified)

    // method to get the len of the string
    printf("str1 length: %zu\n",strlen(str1));

    // method to copy string
    char str3[20];
    strcpy(str3, str2); // str3 is destination
    printf("str3 is: %s\n", str3);

    //method to concat
    strcat(str1, str2); // concat str2 to str1

    //string compare
    strcmp(str1, str2); // returns 0 if equal


    //string reversal in O(log(n))
    char str4[6] = "hello";
    reverse_string(str4);

}


//return struct type
ae get_max(int a, int b) {
    ae ele;

    if(a > b) {
        ele.ele1 = a;
        ele.ele2 = b;
    }else{
        ele.ele1 = b;
        ele.ele2 = a;
    }
    return ele;
}


struct Arr {
    int *arr;
    int size;
};

typedef struct Arr arr; // another name to struct Arr

//dot and arrow operator
void dot_and_arrow_oper() {
    
    // if struct is an instance of a strucute, then dot is used
    arr array; // this is the structure instance
    array.size = 5;
    array.arr = (int *)malloc(array.size * sizeof(int)); // dot operator is used bcz of the arr is instance not pointer reference.

    for(int i=0;i<array.size; i++) {
        array.arr[i] = i+1;         // dot oper is used bcz of struct instance 
    }

    // if struct is a pointer, then arrow -> oper is used
    arr *a;
    a = &array;
    for(int i=0;i<a->size; i++) {
        printf("ele: %d\t",a->arr[i]); // arrow oper bcz structure pointer is used.
    }

}

// ************************************************** memory allocation of different type of variables *********************************

// Global variables
int global_var = 10; // Initialized Data Segment
int uninitialized_global_var; // BSS Segment

void example_function() {
    static int static_var = 20; // Initialized Data Segment
    int local_var = 30; // Stack Segment
    int *dynamic_var = (int *)malloc(sizeof(int)); // Heap Segment

    // Use dynamic_var
    free(dynamic_var); // Free dynamically allocated memory
}

int main() {
    // size of each data type in C
    char c; // 1byte
    short int si; // 2 bytes 
    int i = 10; // 4 bytes
    float f = 0.1f; // 4 bytes
    long int l = 1; // 4 bytes in 32bit machine and 8 bytes in 64bit machine [difference]
    double d = 1.1f; // 8 bytes 
    unsigned int ui; // 4 bytes
    long double ld; //16 bytes [12 or 16byte in 32bit and 16bytes in 64bit machine][differece]
    long long int lli; // 8 bytes
    long double size = sizeof(ld);
    int *tptr; // 4bytes in 32bit machine and 8 bytes in 64bit machine [difference]

    // var types based on the memory and type
    // register - tell compiler store the value in cpu registers
    // volatile - tell compiler to not to optimise the data in this var
    // extern - tell compiler that definition of this variable is other file

    unsigned char x = 0xFF; // because range is 0-255
    char a = 0x80; // overflow because range is -128 to 127
    printf("val %d\n",x); // 255
    printf("val %d\n",a); // -128 overflow. value gets wrapped because not within range

    printf("size: %Lf\n",size);
    int arr[2]; // this is static allocation of memory, therefore memory is allocated in Stack

    printf("%d\n",arr[3]); // throws warning and not error
    
    //get maximum value - demonstrates multiple return values. struct is used.
    ae ele = get_max(9, 10);
    printf("\nmax ele %d is greather than %d\n",ele.ele1, ele.ele2);

    arr_malloc(); // dynamic memory allocation is in Heap memory
    mem_calloc(); // 2-d array // memory allocation happens in Heap
    
    assign_and_callback(); //call back function

    sizeof_str_and_union(); // calc sizeof structure

    string_operations(); //strcpy, strcmp, strcat
    
    dot_and_arrow_oper();
    /*
    - to access members you need to use dot operator
    -  if a pointer is used, then -> operator is used.
    */

    return 0;
}