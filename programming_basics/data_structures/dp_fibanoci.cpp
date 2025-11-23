#include<iostream>


int res = 0;

int fibanoci_recursive(int number) {

    if (number == 0) return 0;

    if (number == 1) return 1;

    res = fibanoci_recursive(number - 1)  + fibanoci_recursive(number-2);
    
    // 0 1 1 2 3 5
    return res;
}

int main() {
    
    int n;
    std::cout<<"enter the fibanoci number"<<std::endl;
    std::cin>>n;

    std::cout<<"Fib of " << n<< " is: "<<fibanoci_recursive(n-1)<<std::endl;

    return 0;
}