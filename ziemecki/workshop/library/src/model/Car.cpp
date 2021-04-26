//
// Created by student on 25.04.2021.
//

#include "model/Car.h"

using namespace std;

Car::Car(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement,
         const SegmentType &segment) : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment) {}

Car::~Car() {

}

double Car::getActualRentalPrice() {
    return ((MotorVehicle::getActualRentalPrice()*segment)/10);
}

std::string Car::getVehicleInfo() {
    return ("Car " + MotorVehicle::getVehicleInfo() + " " + to_string(segment) + "\n");
}

const SegmentType& Car::get_segment() const {
    return segment;
}

