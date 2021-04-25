//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

class Client;
class Vehicle;
class Address;
class Rent;
class RentRepository;
class VehicleRepository;
class ClientRepository;
class StorageContainer;

typedef Client *ClientPtr;
typedef Vehicle *VehiclePtr;
typedef Address *AddressPtr;
typedef Rent *RentPtr;
typedef RentRepository *RentRepositoryPtr;
typedef VehicleRepository *VehicleRepositoryPtr;
typedef ClientRepository *ClientRepositoryPtr;
typedef StorageContainer *StorageContainerPtr;
typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*RentPredicate)(RentPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);



#endif //CARRENTAL_TYPEDEFS_H