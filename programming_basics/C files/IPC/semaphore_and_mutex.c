/*
race condition can be solved using semphors wait and signal mechanism 
which solves race condition and consistency of shared resource

Semaphor:
1. counting semaphor
2. binary semaphor

Mutex:
1. locking mechanism

*/

/*
Race condition: multiple thread try to update same variable (critical section of code) simultaniously which 
            lead to erroroneous value.

            To solve this, semaphor or mutex(lock) mechanism is used to solve.
*/


/*

1. mutex locking mechanism
2. semaphors

*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>



int counter = 0
void thread_func(void *arg){
    sem_wait(&semaphore); // will decrement the value
    //critical section - start 
    counter++;
    // critical section - end
    sem_post(&semaphor); // Increase semaphore value.
}

void semaphors() { 

    //binary semaphore

    sem_t semaphore;
    pthread_t thread[2];
    int ids[2];

    sem_init(&semaphore, 0, 1); // allowing only one thread enter critical section

    //create two threads
    for (int i=0;i<2;i++) {
        pthread_create(&thread[0], NULL, thread_func, NULL)
    }

    //wait for threads to exit
    for(int i =0;i<2;i++) {
        pthread_join(&thread[0], NULL, thread_func, NULL);
    }

    sem_destroy(&semaphore);

}

pthread_mutex_t lock;

void thread_func_for_lock(void *args){
    pthread_mutex_lock(&lock);
    counter++;      //crtical section
    pthread_mutex_unlock(&lock);
}

void mutex_locking(){

    pthread_t thread1, thread2;
    phtread_mutex_init(&lock);

    pthread_create(&thread1, NULL, thread_func_for_lock, NULL);
    pthread_create(&thread2, NULL, thread_func_for_lock, NULL);

    pthread_join(thread1, NULL);
    phtread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
}

int main() {


    //threads

    /*
    pthread_t
    pthread_create
    pthread_join
    */


    // semaphore
    /*
    sem_t
    sem_init()
    sem_wait()
    sem_post()
    sem_destroy()
    */
    semaphors()


    //mutex lock and unlock
    /*
    pthread_mutex
    pthread_create
    pthread_mutex_lock
    pthread_mutex_unlock
    */
    mutex_locking()

}

