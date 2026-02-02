#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5
int buffer[SIZE];
int count = 0;  // Number of items in the buffer

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    for (int i = 0; i < SIZE * 2; i++) { // Producing more items than buffer size
        pthread_mutex_lock(&lock);
        
        while (count == SIZE) {
            pthread_cond_wait(&cond_producer, &lock);  // Wait if buffer is full
        }

        buffer[count] = i * 10;
        printf("Producer: Added %d to buffer[%d]\n", buffer[count], count);
        count++;

        pthread_cond_signal(&cond_consumer);  // Notify consumer
        pthread_mutex_unlock(&lock);

        sleep(1);  // Simulate production delay
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < SIZE * 2; i++) { // Consuming same amount as produced
        pthread_mutex_lock(&lock);

        while (count == 0) {
            pthread_cond_wait(&cond_consumer, &lock);  // Wait if buffer is empty
        }

        int value = buffer[count - 1];
        printf("Consumer: Read buffer[%d] = %d\n", count - 1, value);
        count--;

        pthread_cond_signal(&cond_producer);  // Notify producer
        pthread_mutex_unlock(&lock);

        sleep(2);  // Simulate consumption delay
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond_producer);
    pthread_cond_destroy(&cond_consumer);

    return 0;
}
