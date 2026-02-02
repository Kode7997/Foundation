#include "vehicle_factory.hpp"

Vehicle* VehicleFacotory::get_vehicle(std::string vehicleType){
    Vehicle *vehicle;
    if(vehicleType == "car"){
        vehicle = new Car();
    }else if(vehicleType == "bike"){
        vehicle = new Bike();
    }
    return vehicle;
}