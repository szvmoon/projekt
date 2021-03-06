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
    stringstream stream;

    for(int i=0; i<vehicleRepository.size();i++)
    {
        stream << vehicleRepository[i]->getVehicleInfo();
    }

    return stream.str();;
}

int VehicleRepository::size() {
    return vehicleRepository.size();
}

vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const{
    vector<VehiclePtr> found;
    for (unsigned int i = 0; i < vehicleRepository.size(); i++) {
        VehiclePtr vehicle = get(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

std::vector<VehiclePtr> VehicleRepository::findAll()  {
    return findBy([](VehiclePtr ptr){return ptr != nullptr;});
}

VehiclePtr VehicleRepository::findByPlateNumber(const string &plateNumber) {
        VehiclePtr found = nullptr;
        for (unsigned int i = 0; i < vehicleRepository.size(); i++) {
            VehiclePtr vehicle = get(i);
            if (vehicle != nullptr && vehicle->get_plateNumber() == plateNumber) {
                found = vehicle;
            }
        }
        return found;
    }

