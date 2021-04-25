//
// Created by student on 25.04.2021.
//

#include "../../repositories/RentRepository.h"

using namespace std;

RentRepository::RentRepository() {}
RentRepository::~RentRepository() {}
RentPtr RentRepository::get (const int &id) const {
    if (id < 0 || rentRepository.size()) {
        return nullptr;
    } else {
        return rentRepository[id];
    }
}
void RentRepository::add (RentPtr newRent){
    if (newRent != nullptr){
        rentRepository.push_back(newRent);
    }
}
void RentRepository::remove (RentPtr to_remove){
    if(to_remove!=nullptr)
        rentRepository.erase(std::remove(rentRepository.begin(), rentRepository.end(), to_remove), rentRepository.end());
}
const string RentRepository::report () const {
    stringstream allrents;
    for (int i=0; i<=rentRepository.size(); i++){
        allrents << rentRepository[i]->getRentInfo();
    }
    return allrents.str();
}
int RentRepository::size () {
    return rentRepository.size();
}