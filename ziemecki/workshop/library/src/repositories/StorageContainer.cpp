//
// Created by student on 18.04.2021.
//

#include "repositories/StorageContainer.h"

StorageContainer::StorageContainer() {
    AddressPtr A1 = new Address("wwa","jasna","1");
    VehiclePtr V1 = new Vehicle("ELC", 20);
    ClientPtr K1 = new Client("Szymon","Ziemecki","123",A1);
    RentPtr R1 = new Rent(1,K1,V1,pt::ptime(gr::date(2021,5,16)));
    clientRepository.add(K1);
    rentRepository.add(R1);
    vehicleRepository.add(V1);

}

StorageContainer::~StorageContainer() {}

ClientRepositoryPtr StorageContainer::getClientRepository() {
    return &clientRepository;
}

VehicleRepositoryPtr StorageContainer::getVehicleRepository() {
    return &vehicleRepository;
}

RentRepositoryPtr StorageContainer::getRentRepository() {
    return &rentRepository;
}
