//
// Created by student on 11.04.2021.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string plateNumber;
    int basePrice;
    bool rented=false;
public:
    //Konstruktor destruktor
    Vehicle(const std::string &, const int &);
    ~Vehicle();

    //Gettery
    const std::string& get_plateNumber() const;
    const int& get_basePrice() const;
    const bool& isRented() const;
    //Settery
    void set_plateNumber(const std::string &);
    void set_basePrice(const int&);
    void set_RentStatus(const bool&);

    //Metody
    std::string getVehicleInfo() const;
};


#endif //CARRENTAL_VEHICLE_H
