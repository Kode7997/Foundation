#include<iostream>

/*
reference: https://en.algorithmica.org/hpc/architecture/indirect/
1. Avoid multiple if, else if, else if, ... block. follow Method1 to optimise
2. Avoid runtime polymorphism, as it creates virtual table and need to figure next instruction till condition gets
computed.  #dynamic dispatch
*/




using namespace std;

int main(){
    
    // Method   
    static const void* table[] = { &&winter, &&summer, &&fall };

    goto *table[1];

    winter:
        cout<<"winter"<<endl;
        return 0;
    summer:
        cout<<"summer"<<endl;
        return 0;
    fall:
        cout<<"fall"<<endl;

    return 0;
}
