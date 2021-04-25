//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "MotorVehicle.h"
class Moped : public MotorVehicle {
public:
    Moped(const std::string&,const int&, const int &);
    ~Moped();
    double getActualRentalPrice();
    virtual std::string getVehicleInfo() override;
};


#endif //CARRENTAL_MOPED_H
