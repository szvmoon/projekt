//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze : public ClientType {
public:
    virtual std::string getTypeInfo() override;
    virtual int getMaxVehicles() override;
    virtual double applyDiscount(const double &) override;
};


#endif //CARRENTAL_BRONZE_H
