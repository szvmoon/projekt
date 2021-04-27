//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "ClientType.h"

class Silver : public ClientType{
public:
    Silver();
    ~Silver();
    virtual int getMaxVehicles() override;
    virtual std::string getTypeInfo() override;
    virtual double applyDiscount(const double &) override;
};


#endif //CARRENTAL_SILVER_H
