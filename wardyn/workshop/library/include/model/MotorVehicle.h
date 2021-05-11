//
// Created by student on 28.04.2021.
//

#ifndef CARRENTALPROJECT_MOTORVEHICLE_H
#define CARRENTALPROJECT_MOTORVEHICLE_H
#include "model/Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    MotorVehicle (const string &, const int &, const int &);
    virtual ~MotorVehicle ()=0;
    virtual double getActualRentalPrice ();
    const string getVehicleInfo() const;
    int getengineDisplacement();
    void setengineDisplacement(const int&);

};


#endif //CARRENTALPROJECT_MOTORVEHICLE_H
