//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "ClientType.h"

class Platinum : public ClientType {
public:
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
    virtual double applyDiscount(double price) override;
};


#endif //CARRENTAL_PLATINUM_H
