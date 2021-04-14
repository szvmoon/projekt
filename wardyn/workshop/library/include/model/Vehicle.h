//
// Created by student on 05.04.2021.
//

#ifndef CARRENTALPROJECT_VEHICLE_H
#define CARRENTALPROJECT_VEHICLE_H
#include <iostream>

using namespace std;

class Vehicle
{
private:
    string plateNumber;
    int basePrice;
    bool rented=false;
public:
    Vehicle(const string&, const int&);
    ~Vehicle();
    const string getVehicleInfo () const;
    const string getplateNumber () const;
    const string getrented () const;
    const int getbasePrice () const;
    void setplateNumber (const string&);
    void setbasePrice (const int&);
    void setrented (bool);
};

#endif //CARRENTALPROJECT_VEHICLE_H
