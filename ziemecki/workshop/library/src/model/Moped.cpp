//
// Created by student on 25.04.2021.
//

#include "model/Moped.h"

Moped::Moped(const std::string & plateNumber, const int &basePrice, const int &engineDisplacement) : MotorVehicle(plateNumber,basePrice,engineDisplacement){}

Moped::~Moped() {

}

double Moped::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getVehicleInfo() {
    return ("Moped " + MotorVehicle::getVehicleInfo() + "\n");
}
