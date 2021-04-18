//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H

#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"
#include "typedefs.h"

class StorageContainer {
private:
    ClientRepository clientRepository;
    VehicleRepository vehicleRepository;
    RentRepository rentRepository;
public:
    StorageContainer();
    ~StorageContainer();
    ClientRepository getClientRepository() ;
    VehicleRepository getVehicleRepository();
    RentRepository getRentRepository();

};


#endif //CARRENTAL_STORAGECONTAINER_H
