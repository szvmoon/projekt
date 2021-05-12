//
// Created by student on 11.05.2021.
//

#ifndef CARRENTAL_LOGICCONTAINER_H
#define CARRENTAL_LOGICCONTAINER_H

#include "managers/ClientManager.h"
#include "managers/VehicleManager.h"
#include "managers/RentManager.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Default.h"
#include "model/Diamond.h"

class LogicContainer {
public:
    LogicContainer();
    ClientManager &getClientManager();
    VehicleManager &getVehicleManager();
    RentManager &getRentManager();

private:
    RentManager rentManager;
    ClientManager clientManager;
    VehicleManager vehicleManager;
    AddressPtr address;
    AddressPtr address2;
    ClientTypePtr memberDefault;
    ClientTypePtr memberDiamond;
};



#endif //CARRENTAL_LOGICCONTAINER_H
