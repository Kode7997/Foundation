#include<iostream>


int counter = 0;
int a=1, b=1;
int main(){

    /*
    - Implemented using capture class = [], used to indicate if variables captured from outer scope
    auto lambda = []() -> return_type {
        // functionality implementation
    }

    auto lambda = [=](){} // capture by value
    auto lambda = [&](){}
    */
    auto x = 10;
    auto y = 11;

    auto add = [](auto x, int y) -> int { // neither capture by value nor the reference.
        return x+y;
    };

    auto s = add(x,y);
    std::cout<<"s: "<<s<<std::endl;

    auto sub = [&]() -> int { // capture by refernce
        a = a+b;
        return a-b;
    };

    int v = sub();
    std::cout<<"v: "<<v<<std::endl;
    std::cout<<"a: "<<a<<std::endl;


}