//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include "typedefs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "model/Vehicle.h"
#include "model/Bicycle.h"
#include "model/MotorVehicle.h"
#include "model/Moped.h"
#include "model/Car.h"

class VehicleRepository {
private:
    std::vector <VehiclePtr> vehicleRepository;
public:
    VehicleRepository();
    ~VehicleRepository();
    VehiclePtr get(const int &) const;
    void add(VehiclePtr) ;
    void remove(VehiclePtr);
    const std::string report() const;
    int size();
    std::vector<VehiclePtr> findBy(VehiclePredicate) const;
    std::vector<VehiclePtr> findAll();

};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
