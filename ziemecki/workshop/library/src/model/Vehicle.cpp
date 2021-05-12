//
// Created by student on 11.04.2021.
//

#include "model/Vehicle.h"

using namespace std;

Vehicle::Vehicle(const string &plateNumber, const int &basePrice) : plateNumber(plateNumber), basePrice(basePrice) {}

Vehicle::~Vehicle() {}

const string& Vehicle::get_plateNumber() const { return plateNumber; }

const int& Vehicle::get_basePrice() const { return basePrice; }

void Vehicle::set_plateNumber(const string &pNumber) {
    if (pNumber != "")
        plateNumber = pNumber;
}

void Vehicle::set_basePrice(const int &bPrice) { basePrice = bPrice; }

string Vehicle::getVehicleInfo()  {
    return (plateNumber + " " + to_string(basePrice));
}

const void Vehicle::setArchive(bool arg) {
    archive = arg;
}

const bool Vehicle::isArchive() const{
    return archive;
}

//const bool& Vehicle::isRented() const { return rented; }

//void Vehicle::set_RentStatus(const bool &status) { rented = status; }

