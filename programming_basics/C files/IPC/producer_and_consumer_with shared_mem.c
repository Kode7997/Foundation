/*
TO ESTABLISH THE COMUNICATION BETWEEN TWO PROCESS,
C HAS SHARED MEMORY LIB THAT HELP UTILIZE SHARED RESOURCES EFFICIENTLTY
BETWEEN PROCESSES.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SIZE 1024

void producer() {
//write to the shared memory
void *shm_ptr;
int shm_fd;

// create shm 
shm_fd = shm_open("shared_mem_name", O_CREATE | O_RDWR, 0666);

//configure the memory space which is trunc
ftruncate(shm_fd, SIZE); 

// attach mem to current process address space
//MAP_SHARED - indicate this is shared with other process
//PROT_WRITE - write
shm_ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);


//write
sprintf(shm_ptr, "producer wrote to the shared memory"); // sprintf write to the memory pointer is pointing to
}


void consumer(){

    int shm_id;
    void *shm_ptr;

    //open
    shm_fd = shm_open("shared_mem_name", O_READ, 0666);

    //mmap - memory map to the current process address space. // PROT => protection flag
    shm_ptr = mmap(0, SIZE, PROT_READ, PROT_SHARED, shm_fd, 0);

    //read
    printf("read msg from consumer: %s\n", (char *)shm_ptr);
    
    //close
    close(shm_fd);
}

void main(){

    producer(); //producer.c
    consumer(); //consumer.c
}



/*

Process-Level Mutexes
In POSIX, process-level mutexes can be implemented using pthread_mutex_t with shared memory. This involves the following steps:
Creating Shared Memory: Use shm_open to create a shared memory object.
Mapping Shared Memory: Use mmap to map the shared memory object into the process's address space.
Initializing Mutex: Initialize the mutex with the PTHREAD_PROCESS_SHARED attribute.


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

// Define a structure with a mutex
typedef struct {
    pthread_mutex_t mutex;
    int counter;
} SharedData;

int main() {
    int fd;
    SharedData *sharedData;
    pthread_mutexattr_t mutexAttr;

    // Create shared memory object
    fd = shm_open("/mysharedmem", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Set the size of the shared memory object
    if (ftruncate(fd, sizeof(SharedData)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object into the process's address space
    sharedData = (SharedData *)mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (sharedData == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Initialize the mutex attribute for process sharing
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_SHARED);

    // Initialize the mutex in shared memory
    pthread_mutex_init(&sharedData->mutex, &mutexAttr);

    // Initialize the counter
    sharedData->counter = 0;

    // Increment the counter with the mutex locked
    pthread_mutex_lock(&sharedData->mutex);
    sharedData->counter++;
    printf("Counter: %d\n", sharedData->counter);
    pthread_mutex_unlock(&sharedData->mutex);

    // Clean up
    pthread_mutex_destroy(&sharedData->mutex);
    pthread_mutexattr_destroy(&mutexAttr);
    munmap(sharedData, sizeof(SharedData));
    shm_unlink("/mysharedmem");

    return 0;
}


*/