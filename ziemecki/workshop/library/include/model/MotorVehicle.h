//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include "Vehicle.h"
#include <string>

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    MotorVehicle(const std::string&,const int&, const int &);
    virtual ~MotorVehicle()=0;
    virtual double getActualRentalPrice() ;
    virtual std::string getVehicleInfo() override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
