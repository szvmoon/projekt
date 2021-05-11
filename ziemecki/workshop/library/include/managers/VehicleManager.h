//
// Created by student on 11.05.2021.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include "typedefs.h"
#include "repositories/VehicleRepository.h"
#include <vector>

class VehicleManager {
private:
    VehicleRepository vehicleRepository;
public:
    VehiclePtr getVehicle(const std::string &plateNumber);
    VehiclePtr registerBicycle(const std::string &plateNumber, const int &basePrice);
    VehiclePtr registerMoped(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement);
    VehiclePtr registerCar(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement, SegmentType segment);
    void unregisterVehicle(VehiclePtr &vehicle);
    std::vector<VehiclePtr> findVehicles(VehiclePredicate);
    std::vector<VehiclePtr> findAllVehicles();
};


#endif //CARRENTAL_VEHICLEMANAGER_H
