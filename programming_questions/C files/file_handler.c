/*
1. file operations
2. IPC
3. Socket programming
4. Deadlock and mutual exclusion
5. producer-consumer problem
6. semaphor to solve race condition
7. LRU cache
*/

#include <stdio.h>

void write_and_read_file() {

    FILE *fp;
    fp = fopen("random.txt","rw+");
    if (fp != NULL){
        fprintf(fp, "hello world\n");
        fprintf(fp, "keshav is learning something\n");
        fputs("Hello world\n",fp);
    }

    printf("read from a file\n");
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
  
    fclose(fp);
}


void ipc_comm() {

    
}






int main(){
    write_and_read_file();
    ipc_comm()
    return 0;

}



