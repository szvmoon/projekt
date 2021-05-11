//
// Created by student on 11.05.2021.
//

#include "managers/VehicleManager.h"

VehiclePtr VehicleManager::getVehicle(const std::string &plateNumber) {
    return vehicleRepository.findByPlateNumber(plateNumber);
}

VehiclePtr VehicleManager::registerBicycle(const std::string &plateNumber, const int &basePrice) {
    if(vehicleRepository.findByPlateNumber(plateNumber)->get_plateNumber() == plateNumber)
        return vehicleRepository.findByPlateNumber(plateNumber);
    else {
        VehiclePtr newBicycle = std::make_shared<Bicycle>(plateNumber,basePrice);
        vehicleRepository.add(newBicycle);
        return newBicycle;
    }

}

VehiclePtr
VehicleManager::registerMoped(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement) {
    if(vehicleRepository.findByPlateNumber(plateNumber)->get_plateNumber() == plateNumber)
        return vehicleRepository.findByPlateNumber(plateNumber);
    else {
        VehiclePtr newMoped = std::make_shared<Moped>(plateNumber,basePrice,engineDisplacement);
        vehicleRepository.add(newMoped);
        return newMoped;
    }
}

VehiclePtr
VehicleManager::registerCar(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement,
                            SegmentType segment) {
    if(vehicleRepository.findByPlateNumber(plateNumber)->get_plateNumber() == plateNumber)
        return vehicleRepository.findByPlateNumber(plateNumber);
    else {
        VehiclePtr newCar = std::make_shared<Car>(plateNumber,basePrice,engineDisplacement,segment);
        vehicleRepository.add(newCar);
        return newCar;
    }
}



std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate) {
    return std::vector<VehiclePtr>();
}

std::vector<VehiclePtr> VehicleManager::findAllVehicles() {
    return std::vector<VehiclePtr>();
}

void VehicleManager::unregisterVehicle(VehiclePtr &vehicle) {
    if(getVehicle(vehicle->get_plateNumber()) != nullptr)
        vehicle->setArchive(true);
}
