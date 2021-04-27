//
// Created by student on 27.04.2021.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>

class ClientType {
public:
    ClientType();
    virtual ~ClientType() = 0;
    virtual int getMaxVehicles();
    virtual double applyDiscount();
    virtual std::string getTypeInfo();
};


#endif //CARRENTAL_CLIENTTYPE_H
