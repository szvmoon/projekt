//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond : public ClientType {
public:
    std::string getTypeInfo() override;
    int getMaxVehicles() override;
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_DIAMOND_H
