//
// Created by student on 25.04.2021.
//


#include "../../repositories/VehicleRepository.h"
using namespace std;

VehicleRepository::VehicleRepository() {}
VehicleRepository::~VehicleRepository() {}
VehiclePtr VehicleRepository::get (const int &id) const {
    if (id < 0 || vehicleRepository.size()) {
        return nullptr;
    } else {
        return vehicleRepository[id];
    }
}
void VehicleRepository::add (VehiclePtr newVehicle){
    if (newVehicle != nullptr){
        vehicleRepository.push_back(newVehicle);
    }
}
void VehicleRepository::remove (VehiclePtr to_remove){
    if(to_remove!=nullptr)
        vehicleRepository.erase(std::remove(vehicleRepository.begin(), vehicleRepository.end(), to_remove), vehicleRepository.end());
}
const string VehicleRepository::report () const {
    stringstream allvehicles;
    for (int i=0; i<=vehicleRepository.size(); i++){
        allvehicles << vehicleRepository[i]->getVehicleInfo();
    }
    return allvehicles.str();
}
int VehicleRepository::size () {
    return vehicleRepository.size();
}