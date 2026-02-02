#include <stdio.h>
#include <unistd.h>

#define SIZE 100 

/*

Inter-Process Communication - this can be achieved using PIPE, Socket, message queues and shared memory techniques to improve performance
of the program.

1. one-way pipe communication
2. two way communiation using pipe
3. difference between thread and process?
*/

int main() {
    // fd[0] read, fd[1] write
    int fd[2];
    pipe(fd); // create of one-way
    if (fork() == 0) {   //child process
        close(fd[0]);
        write(fd[1], "hello keshav, child writes\n", 50); //14 is number of char
        close(fd[1]);
    } else {            // parent process
        close(fd[1]);
        char buffer[SIZE];
        read(fd[0], buffer, SIZE);
        buffer[SIZE-1] = '\0';
        printf("-read data from child: %s\n",buffer);
        close(fd[0]);
    }
    
    /*
    2-way communication can be achieved using but need 2 pipes.
    - this is used within the related process
    - whether child process executes first or parent process excutes first is not sure. every time output will differs. if sync is needed
        wait or sleep time is added to either parent or child
    */

    return 0;
    
}

/*
Note:

communication between two processes.

1. Say if  two processes file1.c need file2.c need to exchange data, then default pipe cannot work. 
    - here, named pipe need to be used to exchange data
    - eg: mkfifo /tmp/my_fifo 
    - writer:
        int fd
        fd = open("/tmp/my_fifo", WRONLY)
        write(fd, "message", size)
    
    - reader:
        int fd
        fd  = open("/tmp/my_fifo", RDONLY)
        read(fd, buffer, size)

    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h> //status of a file
    #include <unistd.h>

    int main() {
        const char *fifo_name = "/tmp/my_fifo";
        mkfifo(fifo_name, 0666);

        int fd = open(fifo_name, O_WRONLY);
        write(fd, "Hello from writer!\n", 19);
        close(fd);

        return 0;
}


*/