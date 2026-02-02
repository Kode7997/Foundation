#include "car.hpp"
#include "bike.hpp"
#include "iostream"

using namespace std;

int main(){

    string vehicleType;
    cin>>vehicleType;
    Vehicle *vcle;
    if(vehicleType == "car"){
        vcle = new Car();
    }else if(vehicleType == "bike"){
        vcle = new Bike();
    }

    vcle->create_vehicle();


    return 0;
}