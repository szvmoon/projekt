//
// Created by student on 25.04.2021.
//

#include "model/Bicycle.h"

Bicycle::Bicycle(const std::string & plateNumber, const int &basePrice) : Vehicle(plateNumber,basePrice) {}

Bicycle::~Bicycle() {

}

double Bicycle::getActualRentalPrice() {
    return get_basePrice();
}

std::string Bicycle::getVehicleInfo() {
    return "Bicycle " + Vehicle::getVehicleInfo() + "\n";
}
