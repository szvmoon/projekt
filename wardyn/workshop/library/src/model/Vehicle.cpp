//
// Created by student on 05.04.2021.
//

#include "model/Vehicle.h"
#include <string>
#include <iostream>

using namespace std;

Vehicle::Vehicle(const string &plateNumber, const int &basePrice): plateNumber(plateNumber), basePrice(basePrice) {}
Vehicle::~Vehicle() {}
const string Vehicle::getVehicleInfo() const
{
    return ("Pojazd: "+plateNumber+", "+to_string(basePrice));
}

const string Vehicle::getplateNumber() const
{
    return (plateNumber);
}
const int Vehicle::getbasePrice() const
{
    return (basePrice);
}
void Vehicle::setplateNumber(const string &plate)
{
    if (plate != "")
    {
        plateNumber = plate;
    }
}
void Vehicle::setbasePrice(const int &price)
{
    basePrice = price;
}
