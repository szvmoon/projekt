//
// Created by student on 18.04.2021.
//

#include "repositories/StorageContainer.h"
using namespace std;

StorageContainer::StorageContainer() {
    AddressPtr A1 = make_shared<Address>("wwa","jasna","1");
    BicyclePtr V1 = make_shared<Bicycle>("ELC", 20);
    ClientPtr K1 = make_shared<Client>("Szymon","Ziemecki","123",A1);
    RentPtr R1 = make_shared<Rent>(1,K1,V1,pt::ptime(gr::date(2021,5,16)));
    clientRepository.add(K1);
    rentRepository.add(R1);
    vehicleRepository.add(V1);

}

StorageContainer::~StorageContainer() {
}

ClientRepository * StorageContainer::getClientRepository() {
    return &clientRepository;
}

VehicleRepository * StorageContainer::getVehicleRepository() {
    return &vehicleRepository;
}

RentRepository * StorageContainer::getRentRepository() {
    return &rentRepository;
}
