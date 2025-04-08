#include<iostream>


int counter = 0;

int main(){

    /*
    - Implemented using capture class = [], used to indicate if variables captured from outer scope
    auto lambda = []() -> return_type {
        // functionality implementation
    }

    auto lambda = [=](){}
    auto lambda = [&](){}
    */
    auto x = 10;
    auto y = 11;

    auto add = [=](auto x, int y) -> int {
        return x+y;
    };

    add(x,y);




}