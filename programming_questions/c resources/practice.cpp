#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

void get_all_set_bits(int num){

    vector<char> res;

    while (num > 0){
        if(num & 1){
            res.push_back('1');
        }
        num = num >> 1;
    }

    for (int i=0;i<res.size();i++){
        cout << res[i];
    }

    for(char b: res) {
        cout << b;
    };

    return;
}

int main(){
    int *p;
    int a = 10;
    p = &a;
    cout << "p is: "<< (p+1) << " "<< p << endl;


    string sentence = "i am string";

    for (int i=0;i<sentence.length();i++){
        cout << sentence[i] << endl;
    }


    uint16_t n = 10;
    uint64_t n1 = (uint64_t)n;
    //n1 = (int)n1;
    cout << "size of 16bit\t"<< sizeof(n1) <<" "<<n1<< endl;


    get_all_set_bits(15);

    return 0;
}