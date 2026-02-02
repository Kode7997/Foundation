// Program demonstrates Anti-RAII
// Uses C files

#include<iostream>
#include <cstdio>
class Resource1 {

    public:
        Resource1()
        {   
            std::cout<<"constructor1 called"<<std::endl;
            FILE* f = fopen("data.txt","r");
        }

        void process()
        {
            FILE* f1 = fopen("data.txt","w");
            
            // func_cal(); if this function throw exception then this resource is not released, 
            // leads to leak.

            fclose(f1);
        }
};

int main(){

   Resource1 r; // resource created but not destroyed.
   // resource is leaked. when object "r" goes out of scope resource is not released
   // violates RAII principle.
}