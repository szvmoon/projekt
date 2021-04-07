//
// Created by student on 06.04.2021.
//

#ifndef CARRENTALPROJECT_RENT_H
#define CARRENTALPROJECT_RENT_H
#include "model/Client.h"
#include "model/Vehicle.h"
#include <iostream>

using namespace std;

class Rent {
private:
    const int id;
    const Client *client;
    const Vehicle *vehicle;
public:
    Rent(int &, Client *, Vehicle *);
    ~Rent();
    const string getRentInfo() const;
    const int getid() const;
    const Client *getclient() const;
    const Vehicle *getvehicle() const;
};


#endif //CARRENTALPROJECT_RENT_H
