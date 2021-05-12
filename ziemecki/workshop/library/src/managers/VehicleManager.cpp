//
// Created by student on 11.05.2021.
//

#include "managers/VehicleManager.h"

VehiclePtr VehicleManager::getVehicle(const std::string &plateNumber) {
    return vehicleRepository.findByPlateNumber(plateNumber);
}

VehiclePtr VehicleManager::registerBicycle(const std::string &plateNumber, const int &basePrice) {
    VehiclePtr vehicle = vehicleRepository.findByPlateNumber(plateNumber);
    if(vehicle == nullptr)
    {
        VehiclePtr newMoped = std::make_shared<Bicycle>(plateNumber, basePrice);
        vehicleRepository.add(newMoped);
        return newMoped;
    }

    return vehicle;
}

VehiclePtr
VehicleManager::registerMoped(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement) {
    VehiclePtr vehicle = vehicleRepository.findByPlateNumber(plateNumber);
    if(vehicle == nullptr)
    {
        VehiclePtr newMoped = std::make_shared<Moped>(plateNumber, basePrice, engineDisplacement);
        vehicleRepository.add(newMoped);
        return newMoped;
    }

    return vehicle;
}

VehiclePtr
VehicleManager::registerCar(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement,
                            SegmentType segment) {
    VehiclePtr vehicle = vehicleRepository.findByPlateNumber(plateNumber);
    if(vehicle == nullptr)
    {
        VehiclePtr newCar = std::make_shared<Car>(plateNumber, basePrice, engineDisplacement, segment);
        vehicleRepository.add(newCar);
        return newCar;
    }

    return vehicle;
}



std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate predicate) {
    auto function = [&](const VehiclePtr &ptr) -> bool { return (predicate(ptr) && !ptr->isArchive());};
    return vehicleRepository.findBy(function);
}

std::vector<VehiclePtr> VehicleManager::findAllVehicles() {
    return findVehicles([](VehiclePtr ptr) { return ptr != nullptr;});
}

void VehicleManager::unregisterVehicle(VehiclePtr &vehicle) {
    if(getVehicle(vehicle->get_plateNumber()) != nullptr)
        vehicle->setArchive(true);
}
