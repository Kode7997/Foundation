// Memory resource management with RAII

#include<iostream>
#include<memory>

class Resource4
{

    public:
        Resource4(){
            std::cout<<"constructor: "<<std::endl;
        }

        ~Resource4(){
            std::cout<<"destructor: "<<std::endl;
        }

};

void process()
{   
    // RAII
    std::unique_ptr<Resource4> r4 = std::make_unique<Resource4>();
    
    throw std::runtime_error("caught exception in process function");

    std::cout<<"After exception"<<std::endl;
}

int main()
{   
    // if unique_ptr + make_unique combination is not used then manually had to delete heap object created
    // with unique_ptr heap object is deleted automatically.

    /*
        What makes unique_ptr and make_unique special?
        - make_unique creates a heap object and returns unique_ptr that handle/manages pointer.
        - make_unique ensure clear ownership. r5 = r4 not allowed
        - exception safe
        - No reference counting like in shared_ptr
    */

    try
    {
        process();
    }catch (const std::exception& e){
        std::cerr << "Error: "<<e.what()<<std::endl;
    }


}