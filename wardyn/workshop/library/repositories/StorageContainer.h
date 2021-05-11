//
// Created by student on 25.04.2021.
//

#ifndef CARRENTALPROJECT_STORAGECONTAINER_H
#define CARRENTALPROJECT_STORAGECONTAINER_H
#include "ClientRepository.h"
#include "VehicleRepository.h"
#include "RentRepository.h"
#include "typedefs.h"

class StorageContainer {
private:
    ClientRepository CRepository;
    VehicleRepository VRepository;
    RentRepository RRepository;
public:
    StorageContainer();
    ~StorageContainer();
    ClientRepository getClientRepository();
    VehicleRepository getVehicleRepository();
    RentRepository getRentRepository();
};

#endif //CARRENTALPROJECT_STORAGECONTAINER_H
