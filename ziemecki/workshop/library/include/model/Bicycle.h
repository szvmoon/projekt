//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string&, const int&);
    ~Bicycle();
    double getActualRentalPrice() ;
    virtual std::string getVehicleInfo() override;
};


#endif //CARRENTAL_BICYCLE_H
