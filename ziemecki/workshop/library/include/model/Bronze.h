//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze : public ClientType {
public:
    std::string getTypeInfo() override;
    int getMaxVehicles() override;
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_BRONZE_H
