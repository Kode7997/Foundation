#include<iostream>
#include "vehicle_factory.hpp"

int main(){

    std::string vehicleType;
    std::cin>>vehicleType;
    Vehicle* vehicle = VehicleFacotory::get_vehicle(vehicleType);
    vehicle->create_vehicle();
}