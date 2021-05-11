//
// Created by student on 25.04.2021.
//

#include "../../repositories/StorageContainer.h"

StorageContainer::StorageContainer() {
    //tylko dla wygody normalnie tak sie nie robi wiadomka
    AddressPtr A = new Address ("Londyn", "Warecka", "13");
    ClientPtr C = new Client ("Barto", "Kowalski", "69420", A);
    BicyclePtr V = new Bicycle ("EZG79678", 25);
    RentPtr R = new Rent (1, C, V, pt::ptime(gr::date(2025,10,10)));
    CRepository.add(C);
    VRepository.add(V);
    RRepository.add(R);
}
StorageContainer::~StorageContainer() {}
ClientRepository  StorageContainer::getClientRepository () {
    return &CRepository;
}
VehicleRepository  StorageContainer::getVehicleRepository() {
    return &VRepository;
}
RentRepository  StorageContainer::getRentRepository() {
    return &RRepository;
}