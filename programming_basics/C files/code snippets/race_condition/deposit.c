#include "bank.h"
#include<pthread.h>
#include<stdio.h>


pthread_mutex_t lock;

void* deposit(void *amount){

    pthread_mutex_lock(&lock);
    int account_balance = read_balance();
    account_balance += *((int *)amount);
    write_balance(account_balance);
    pthread_mutex_unlock(&lock);

    return NULL;
}


int main() {

    pthread_t t1;
    pthread_t t2;

    int amount1 = 100;
    int amount2 = 200;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, deposit, (void *)&amount1);
    pthread_create(&t2, NULL, deposit, (void *)&amount2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("after: %d\n",read_balance());

    return 0;
}