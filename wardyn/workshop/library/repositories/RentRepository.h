//
// Created by student on 25.04.2021.
//

#ifndef CARRENTALPROJECT_RENTREPOSITORY_H
#define CARRENTALPROJECT_RENTREPOSITORY_H

#include "typedefs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <model/Client.h>

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
    int size ();
};

#endif //CARRENTALPROJECT_RENTREPOSITORY_H
