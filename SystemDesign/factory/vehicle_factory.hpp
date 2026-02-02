#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include "car.hpp"
#include "bike.hpp"
#include<string>

class VehicleFacotory {
    public:
        static Vehicle*  get_vehicle(std::string vehicleType);
};

#endif