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

void producer(){
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
sprintf(shm_ptr, "producer wrote to the shared memory");
}


void consumer(){

    int shm_id;
    void *shm_ptr;

    //open
    shm_fd = shm_open("shared_mem_name", O_READ, 0666);

    //mmap - memory map to the current process address space
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