//
// Created by student on 18.04.2021.
//

#include "repositories/VehicleRepository.h"

using namespace std;

VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {}

VehiclePtr VehicleRepository::get(const int &index) const {
    if(index < 0 || index > vehicleRepository.size())
        return nullptr;
    else
        return vehicleRepository[index];
}

void VehicleRepository::add(VehiclePtr ptr) {
    if(ptr != nullptr)
        vehicleRepository.push_back(ptr);
}

void VehicleRepository::remove(VehiclePtr ptr) {
    if(ptr!= nullptr)
        vehicleRepository.erase(std::remove(vehicleRepository.begin(), vehicleRepository.end(), ptr), vehicleRepository.end());
}

const std::string VehicleRepository::report() const {
    stringstream napis;

    for(int i=0; i<vehicleRepository.size();i++)
    {
        napis << vehicleRepository[i]->getVehicleInfo();
    }

    return napis.str();;
}

int VehicleRepository::size(std::vector<VehiclePtr> v) {
    return v.size();
}
