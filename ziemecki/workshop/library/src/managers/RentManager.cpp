//
// Created by student on 11.05.2021.
//

#include "managers/RentManager.h"

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) const {
    return currentRents.findByClient(client);
}

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle) const {
    return currentRents.findByVehicle(vehicle);
}

std::vector<RentPtr> RentManager::findRents(RentPredicate predicate){
    return currentRents.findBy(predicate);
}

std::vector<RentPtr> RentManager::findAllRents(){
    return currentRents.findBy([](RentPtr ptr){return ptr != nullptr;});
}

double RentManager::checkClientRentBalance(ClientPtr client) const {
    double balance = 0;
    for(const auto x : archiveRents.findByClient(client))
    {
        balance += x->getRentCost();
    }
    return balance;
}

RentPtr RentManager::rentVehicle(ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime beginTime) {
    RentPtr rent = nullptr;
    if(
            !client->isArchive() &&
            !vehicle->isArchive() &&
            (currentRents.findByClient(client).size() < client->getMaxVehicles()) &&
            (currentRents.findByVehicle(vehicle) == nullptr)){
        RentPtr newRent = std::make_shared<Rent>(currentRents.getLastRentId()+1, client, vehicle, beginTime);
        currentRents.add(newRent);
        return newRent;
    }

    else
        return rent;
}

void RentManager::returnVehicle(VehiclePtr vehicle) {
    currentRents.findByVehicle(vehicle)->endRent(boost::posix_time::second_clock::local_time());
    archiveRents.add(currentRents.findByVehicle(vehicle));
    currentRents.remove(currentRents.findByVehicle(vehicle));
}

void RentManager::changeClientType(ClientPtr client) {
    double balance = checkClientRentBalance(client);
    if( balance < 100 ) client->setClientType(std::make_shared<Default>());
    else  if(balance < 200) client->setClientType(std::make_shared<Bronze>());
    else  if(balance < 400) client->setClientType(std::make_shared<Silver>());
    else  if(balance < 800) client->setClientType(std::make_shared<Gold>());
    else  if(balance < 1600) client->setClientType(std::make_shared<Platinum>());
    else  if(balance >= 1600) client->setClientType(std::make_shared<Diamond>());
}
