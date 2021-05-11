//
// Created by student on 28.04.2021.
//

#ifndef CARRENTALPROJECT_BICYCLE_H
#define CARRENTALPROJECT_BICYCLE_H
#include <string>
#include "model/Vehicle.h"
#include "typedefs.h"
using namespace std;

class Bicycle : public Vehicle {
public:
    Bicycle (const string&, const int&);
    virtual double getActualRentalPrice();
    virtual ~Bicycle();
    virtual const string getVehicleInfo() const;
};


#endif //CARRENTALPROJECT_BICYCLE_H
