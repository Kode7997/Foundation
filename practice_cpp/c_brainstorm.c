#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex;


void* print_msg(void *args){

    pthread_mutex_lock(&mutex);
    printf("msg: %s\n",(char *)args);
    pthread_mutex_unlock(&mutex);

    return NULL;
}


int main(){

    pthread_t thread1, thread2;

    struct msg *arg1 = {"msg1 keshav"};
    struct msg *arg2 = {"msg2 cisco"};

    pthread_mutex_init(&mutex,NULL);
    pthread_create(&thread1, NULL, print_msg, (void *)arg1);
    pthread_create(&thread2, NULL, print_msg, (void *)arg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}