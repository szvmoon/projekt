//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold : public ClientType {
public:
    std::string getTypeInfo() override;
    int getMaxVehicles() override;
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_GOLD_H
