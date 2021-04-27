//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "ClientType.h"

class Platinum : public ClientType {
public:
    Platinum();
    ~Platinum();
    virtual int getMaxVehicles() override;
    virtual std::string getTypeInfo() override;
    virtual double applyDiscount(const double &) override;
};


#endif //CARRENTAL_PLATINUM_H
