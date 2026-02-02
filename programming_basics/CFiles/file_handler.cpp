/*
1. file operations
2. IPC
3. Socket programming
4. Deadlock and mutual exclusion
5. producer-consumer problem
6. semaphor to solve race condition
7. LRU cache
*/

#include<iostream>
#include <cstdio> 
#include <cstring> 
#include <cstdlib>

using namespace std;

void write_and_read_file() {

    FILE *fp;
    fp = fopen("random.txt","w+");
    if (fp != NULL){
        fprintf(fp, "hello world\n");
        fprintf(fp, "keshav is learning something\n");
        fputs("Hello world\n",fp);
    }
    
    /*
    If following two lines are not there, then program will lead to segm issue. basically reading while fp is open
    for write.
    r+ => read if file exist
    w+ => create and write to file
    fclose(fp);
    fp = fopen("random.txt","r+");
    */

    printf("read from file\n");
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        //printf("%s", buffer);
        cout << buffer <<endl;
    }
    
    fclose(fp);
}

int main(){
    write_and_read_file();
    return 0;

}