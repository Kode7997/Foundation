#include<iostream>
using namespace std;


int main() {

    int age = 1;
    try {               // try the logic
        if (age>=18){
            cout << "access granted"<<endl;
        }else{
            throw(age); // used to handle custom errors. basically throws exception when error occurs
        }
    } catch(int age) {    // handle the error
        cout <<"access denied bcz age "<<age<<" is not >=18"<<endl;
    }
}