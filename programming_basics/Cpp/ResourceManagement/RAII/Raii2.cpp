// Raii2.cpp
// Program implments RAII principle
// Handles C files

#include<iostream>
#include<cstdio>

class Resource2 {
    
    FILE* file;

    public:
        Resource2()
        {
            file = fopen("data.txt","r");
            if(!file)
            {
                std::cout<<"file not opened"<<std::endl;
            }

            std::cout<<"Contructor: object created"<<std::endl;
        }

        ~Resource2()
        {
            if(file)
            {   
                fclose(file);
                std::cout<<"file closed, resource released"<<std::endl;
            }

            std::cout<<"Destructor: object delete"<<std::endl;
        }
};


// Another way to implement is to use in-built lib that is designed with RAII principle

class Resource2_1{

    public:
        Resource2_1(){

        }
};

int main()
{
    Resource2 r2; // resource created
    
    return 0;   // when object r2 is out of scope then resource is released.
}