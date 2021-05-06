//
// Created by student on 28.04.2021.
//

#ifndef CARRENTALPROJECT_CAR_H
#define CARRENTALPROJECT_CAR_H
#include <string>
#include "MotorVehicle.h"
#include "typedefs.h"
using namespace std;

enum SegmentType{A=10, B=11, C=12, D=13, E=15};

class Car : public MotorVehicle {
private:
    SegmentType segment;
public:
    Car (const string &, const int &, const int &, const SegmentType &);
    virtual ~Car();
    virtual double getActualRentalPrice ();
    string getVehicleInfo() const;
    SegmentType& getSegment();
};

#endif //CARRENTALPROJECT_CAR_H
