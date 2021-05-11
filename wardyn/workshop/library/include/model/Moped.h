//
// Created by student on 28.04.2021.
//

#ifndef CARRENTALPROJECT_MOPED_H
#define CARRENTALPROJECT_MOPED_H
#include <string>
#include "MotorVehicle.h"
#include "typedefs.h"

using namespace std;

class Moped : public MotorVehicle {

    Moped (const string &, const int &, const int &);
    virtual ~Moped ();
    virtual double getActualRentalPrice ();
    string getVehicleInfo() const;


};


#endif //CARRENTALPROJECT_MOPED_H
