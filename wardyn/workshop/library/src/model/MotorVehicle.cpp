//
// Created by student on 28.04.2021.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}
MotorVehicle::~MotorVehicle();
double MotorVehicle::getActualRentalPrice() {
    if (engineDisplacement <= 1000)
        return getbasePrice();
    else if (engineDisplacement <= 1200)
        return getbasePrice()*1.1;
    else if (engineDisplacement <= 1400)
        return getbasePrice()*1.2;
    else if (engineDisplacement <= 1600)
        return getbasePrice()*1.3;
    else if (engineDisplacement <= 1800)
        return getbasePrice()*1.4;
    else
        return getbasePrice()*1.5;
}
const string MotorVehicle::getVehicleInfo() const {
    return "MotorVehicle: "+Vehicle::getVehicleInfo()+to_string(engineDisplacement)+"\n";
}
int MotorVehicle::getengineDisplacement() {
    return engineDisplacement;
}
void MotorVehicle::setengineDisplacement(const int& liters) {
    engineDisplacement=liters;
}