//
// Created by student on 18.04.2021.
//

#include "repositories/RentRepository.h"

using namespace std;


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
    stringstream napis;

    for(int i=0; i<rentRepository.size();i++)
    {
        napis << rentRepository[i]->getRentInfo();
    }

    return napis.str();
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
    findBy([](RentPtr ptr){return ptr != nullptr;});
}

