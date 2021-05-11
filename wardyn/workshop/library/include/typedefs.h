//
// Created by student on 24.04.2021.
//

#ifndef CARRENTALPROJECT_TYPEDEFS_H
#define CARRENTALPROJECT_TYPEDEFS_H

#include <memory>

class Client;
class Address;
class Vehicle;
class Rent;
class RentRepository;
class VehicleRepository;
class ClientRepository;
class StorageContainer;
class Bicycle;
class Car;
class Moped;
class MotorVehicle;

typedef Client *ClientPtr;
typedef Vehicle *VehiclePtr;
typedef Address *AddressPtr;
typedef Rent *RentPtr;
typedef Bicycle *BicyclePtr;
typedef Car *CarPtr;
typedef Moped *MopedPtr;
typedef MotorVehicle *MotorVehiclePtr;
typedef RentRepository *RentRepositoryPtr;
typedef VehicleRepository *VehicleRepositoryPtr;
typedef ClientRepository *ClientRepositoryPtr;
typedef StorageContainer *StorageContainerPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);
typedef bool (*RentPredicate)(RentPtr);

#endif //CARRENTALPROJECT_TYPEDEFS_H
