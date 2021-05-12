//
// Created by student on 11.05.2021.
//

#include "managers/LogicContainer.h"

LogicContainer::LogicContainer() {
    address = std::make_shared<Address>("London", "Accacia Avenue", "22");
    address2 = std::make_shared<Address>("Wysypisko", "Rue Morgue", "13");

    memberDefault = std::make_shared<Default>();
    memberDiamond = std::make_shared<Diamond>();

    vehicleManager.registerBicycle("PN1", 100);
    vehicleManager.registerMoped("PN2", 200, 200);
    vehicleManager.registerCar("PN3", 350, 1200,C);

    clientManager.registerClient("Adam", "Nowak", "123123123", address, memberDiamond);
    clientManager.registerClient("Marcin", "Najman", "007183000", address2, memberDefault);
}

ClientManager &LogicContainer::getClientManager() {
    return clientManager;
}

VehicleManager &LogicContainer::getVehicleManager() {
    return vehicleManager;
}

RentManager &LogicContainer::getRentManager() {
    return rentManager;
}
