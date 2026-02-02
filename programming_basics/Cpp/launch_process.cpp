#include<iostream>
#include<unistd.h>



int main(){


    // fork() will launch another process

    if(!fork()){
        std::cout<<"new process"<<"new pid:"<<getpid()<<std::endl;
    }else{
        std::cout<<"old process"<<" pid:"<<getpid()<<std::endl;
    }
}