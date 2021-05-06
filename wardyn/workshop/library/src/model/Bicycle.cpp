//
// Created by student on 28.04.2021.
//

#include "model/Bicycle.h"

Bicycle::Bicycle(const string & plateNumber, const int &basePrice) : Vehicle (plateNumber, basePrice) {}
Bicycle::~Bicycle() {}
double Bicycle::getActualRentalPrice() {
    return getbasePrice();
}
const string Bicycle::getVehicleInfo() const {
    return "Bicycle: "+Vehicle::getVehicleInfo()+"\n";
}