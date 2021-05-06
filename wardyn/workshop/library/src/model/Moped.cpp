//
// Created by student on 28.04.2021.
//

#include "model/Moped.h"

Moped::Moped (const string &plateNumber, const int &basePrice, const int &engineDisplacement) : Motorvehicle (plateNumber, basePrice, engineDisplacement) {}
Moped::~Moped () {};
double Moped::getActualRentalPrice() {
    MotorVehicle::getActualRentalPrice();
}
string Moped::getVehicleInfo() const {
    return "Moped: "+MotorVehicle::getVehicleInfo()+"\n";
}