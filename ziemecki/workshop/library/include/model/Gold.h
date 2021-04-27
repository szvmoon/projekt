//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold : public ClientType {
public:
    Gold();
    ~Gold();
    virtual std::string getTypeInfo() override;
    virtual int getMaxVehicles() override;
    virtual double applyDiscount(const double &) override;
};


#endif //CARRENTAL_GOLD_H
