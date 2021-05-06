//
// Created by student on 25.04.2021.
//

#ifndef CARRENTALPROJECT_VEHICLEREPOSITORY_H
#define CARRENTALPROJECT_VEHICLEREPOSITORY_H

#include "typedefs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <model/Client.h>

class VehicleRepository {
private:
    std::vector <VehiclePtr> vehicleRepository;
public:
    VehicleRepository();
    ~VehicleRepository();
    VehiclePtr get(const int &) const;
    void add(VehiclePtr);
    void remove(VehiclePtr);
    const std::string report() const;
    int size ();
    vector<VehiclePtr> findBy(VehiclePredicate) const;
    vector<VehiclePtr> findAll ();
};


#endif //CARRENTALPROJECT_VEHICLEREPOSITORY_H
