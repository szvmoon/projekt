//
// Created by student on 28.04.2021.
//

#include "model/Car.h"

Car::Car (const string &plateNumber, const int &basePrice, const int &engineDisplacement, const SegmentType &segment) : MotorVehicle (plateNumber, basePrice, engineDisplacement), segment (segment){}
Car::~Car () {};
double Car::getActualRentalPrice() {
    return ((MotorVehicle::getActualRentalPrice()*segment/10));
}
string Car::getVehicleInfo() const {
    return "Car: "+MotorVehicle::getVehicleInfo()+to_string(segment)+"\n";
}
SegmentType& Car::getSegment() {
    return segment;
}
