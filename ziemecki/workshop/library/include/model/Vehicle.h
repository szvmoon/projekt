//
// Created by student on 11.04.2021.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <string>
#include "typedefs.h"

class Vehicle {
private:
    std::string plateNumber;
    bool rented=false;
protected:
    int basePrice;
public:
    //Konstruktor destruktor
    Vehicle(const std::string &, const int &);
    virtual ~Vehicle()=0;

    //Gettery
    const std::string& get_plateNumber() const;
    const int& get_basePrice() const;
    const bool& isRented() const;
    //Settery
    void set_plateNumber(const std::string &);
    void set_basePrice(const int&);
    void set_RentStatus(const bool&);

    //Metody
    virtual std::string getVehicleInfo();
};


#endif //CARRENTAL_VEHICLE_H
