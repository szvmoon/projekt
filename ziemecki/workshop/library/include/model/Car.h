//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "MotorVehicle.h"

enum SegmentType{A=10,B=11,C=12,D=13,E=15};


class Car : public MotorVehicle {
private:
    SegmentType segment;
public:
    Car(const std::string&,const int&, const int &, const SegmentType&);
    ~Car();
    virtual double getActualRentalPrice() override;
    virtual std::string getVehicleInfo() override;

};


#endif //CARRENTAL_CAR_H
