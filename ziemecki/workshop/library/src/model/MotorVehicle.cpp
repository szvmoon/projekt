//
// Created by student on 25.04.2021.
//

#include "model/MotorVehicle.h"

using namespace std;

MotorVehicle::MotorVehicle(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}

MotorVehicle::~MotorVehicle() {

}

double MotorVehicle::getActualRentalPrice() {
    if(engineDisplacement <= 1000)
        return get_basePrice();
    else if(engineDisplacement <= 1200)
        return get_basePrice()*1.1;
    else if(engineDisplacement <=1400)
        return get_basePrice()*1.2;
    else if(engineDisplacement <=1600)
        return get_basePrice()*1.3;
    else if(engineDisplacement <= 1800)
        return get_basePrice()*1.4;
    else
        return get_basePrice()*1.5;
}

std::string MotorVehicle::getVehicleInfo() {
    return (Vehicle::getVehicleInfo() + " " + to_string(engineDisplacement));
}

const int MotorVehicle::get_engineDisplacement() const {return engineDisplacement;}

const void MotorVehicle::set_engineDisplacement(const int& displacement) {
    engineDisplacement=displacement;
}
