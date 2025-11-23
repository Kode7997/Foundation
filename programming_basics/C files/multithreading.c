#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> //there is no std lib in C for thread, but posix lib helps it.



int counter = 0;
pthread_mutex_t mutex;

struct  msg
{
    char* s1;
    char* additional_msg;
};


void* print_msg(void* info) {

    pthread_mutex_lock(&mutex);   //lock

    struct msg *m = (struct msg *)info;
    printf("msg: %s additional info: %s\n", m->s1, m->additional_msg);
    counter++;
    printf("counter %d\n", counter);
    pthread_mutex_unlock(&mutex); //unlock

    return NULL;
}

int  main() {
    
    pthread_t thread1, thread2;
    struct msg arg1 = {"Hello", "world"};
    struct msg arg2 = {"india","china"};

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, print_msg, &arg1);
    pthread_create(&thread2, NULL, print_msg, &arg2);

    pthread_join(thread1, NULL); // this NULL is retval = return value
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}