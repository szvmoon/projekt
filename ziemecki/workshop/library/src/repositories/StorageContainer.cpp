//
// Created by student on 18.04.2021.
//

#include "repositories/StorageContainer.h"

StorageContainer::StorageContainer() {
    AddressPtr A1 = new Address("wwa","test","1");
    ClientPtr K1 = new Client("Szymon","Ziemecki","123",A1);
    VehiclePtr V1 = new Vehicle("ELc1213",20);
    RentPtr R1 = new Rent(1,K1,V1,pt::ptime(gr::date(2021,5,16)));
    clientRepository.add(K1);
    vehicleRepository.add(V1);
    rentRepository.add(R1);
}

StorageContainer::~StorageContainer() {

}

ClientRepository StorageContainer::getClientRepository() {
    return clientRepository;
}

VehicleRepository StorageContainer::getVehicleRepository() {
    return vehicleRepository;
}

RentRepository StorageContainer::getRentRepository() {
    return rentRepository;
}
