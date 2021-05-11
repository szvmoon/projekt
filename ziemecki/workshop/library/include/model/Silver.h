//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "ClientType.h"

class Silver : public ClientType{
public:
    int getMaxVehicles() override;
    std::string getTypeInfo() override;
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_SILVER_H
