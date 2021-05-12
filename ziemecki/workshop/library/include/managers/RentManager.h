//
// Created by student on 11.05.2021.
//

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include "typedefs.h"
#include "repositories/RentRepository.h"
#include <vector>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Default.h"
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Diamond.h"


class RentManager {
private:
    RentRepository currentRents;
    RentRepository archiveRents;
public:
    RentPtr rentVehicle(ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime beginTime);
    void returnVehicle(VehiclePtr vehicle);
    std::vector<RentPtr> getAllClientRents(ClientPtr client) const;
    RentPtr getVehicleRent(VehiclePtr vehicle) const;
    std::vector<RentPtr> findRents(RentPredicate predicate);
    std::vector<RentPtr> findAllRents() ;
    double checkClientRentBalance(ClientPtr client) const;
    void changeClientType(ClientPtr client);

};


#endif //CARRENTAL_RENTMANAGER_H
