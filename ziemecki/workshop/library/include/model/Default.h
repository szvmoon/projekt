//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "ClientType.h"

class Default : public ClientType{
public:
    virtual int getMaxVehicles() override;
    virtual double applyDiscount() override;
    virtual std::string getTypeInfo() override;
};


#endif //CARRENTAL_DEFAULT_H
