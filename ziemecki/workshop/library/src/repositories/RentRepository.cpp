//
// Created by student on 18.04.2021.
//

#include "repositories/RentRepository.h"

using namespace std;

bool truePredicate(RentPtr ptr)
{
    return true;
}

RentRepository::RentRepository() {}

RentRepository::~RentRepository() {}

void RentRepository::add(RentPtr ptr) {
    if(ptr != nullptr)
        rentRepository.push_back(ptr);
}

RentPtr RentRepository::get(const int &index) const {
    if(index < 0 || index > rentRepository.size())
        return nullptr;
    else
        return rentRepository[index];
}

void RentRepository::remove(RentPtr ptr) {
    if(ptr!= nullptr)
        rentRepository.erase(std::remove(rentRepository.begin(), rentRepository.end(), ptr), rentRepository.end());
}

const std::string RentRepository::report() const {
    stringstream stream;

    for(int i=0; i<rentRepository.size();i++)
    {
        stream << rentRepository[i]->getRentInfo();
    }

    return stream.str();
}

int RentRepository::size() {return rentRepository.size();}

vector<RentPtr> RentRepository::findBy(RentPredicate predicate) {
    vector<RentPtr> found;
    for (unsigned int i = 0; i < rentRepository.size(); i++) {
        RentPtr rent = get(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

std::vector<RentPtr> RentRepository::findAll() {
    return findBy([](RentPtr ptr){return ptr != nullptr;});
}

RentPtr RentRepository::findByVehicle(VehiclePtr vehicle) const {
    RentPtr found = nullptr;
    for (unsigned int i = 0; i < rentRepository.size(); i++) {
        RentPtr rent = get(i);
        if (rent != nullptr && vehicle == rent->get_vehicle()) {
            found = rent;
        }
    }
    return found;
}

std::vector<RentPtr> RentRepository::findByClient(ClientPtr client) const {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < rentRepository.size(); i++) {
        RentPtr rent = get(i);
        if (rent != nullptr && client == rent->get_client()) {
            found.push_back(rent);
        }
    }
    return found;
}

unsigned int RentRepository::getLastRentId() const {
    unsigned int max = 0;
    for (unsigned int i = 0; i < rentRepository.size(); i++) {
        RentPtr rent = get(i);
        if (rent != nullptr) {
            if (max < rent->get_ID())
                max = rent->get_ID();
        }
    }
    return max;
}

