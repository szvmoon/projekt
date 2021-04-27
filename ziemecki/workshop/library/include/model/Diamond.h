//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond : public ClientType {
public:
    Diamond();
    ~Diamond();
    virtual std::string getTypeInfo() override;
    virtual int getMaxVehicles() override;
    virtual double applyDiscount(const double &) override;
};


#endif //CARRENTAL_DIAMOND_H
