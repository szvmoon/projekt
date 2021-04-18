//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H

#include "typedefs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "model/Rent.h"

class RentRepository {
private:
    std::vector <RentPtr> rentRepository;
public:
    RentRepository();
    ~RentRepository();
    RentPtr get(const int &) const;
    void add(RentPtr);
    void remove(RentPtr);
    const std::string report() const;
    int size(std::vector <RentPtr>);
};


#endif //CARRENTAL_RENTREPOSITORY_H
