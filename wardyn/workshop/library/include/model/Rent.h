//
// Created by student on 06.04.2021.
//

#ifndef CARRENTALPROJECT_RENT_H
#define CARRENTALPROJECT_RENT_H
#include "model/Client.h"
#include "model/Vehicle.h"
#include <iostream>
#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
using namespace std;

class Rent {
private:
    const int id;
    const Client *client;
    const Vehicle *vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
public:
    Rent(int &, Client *, Vehicle *, pt::ptime);
    ~Rent();
    const string getRentInfo() const;
    const int getid() const;
    const Client *getclient() const;
    const string getRentDays () const;
    const Vehicle *getvehicle() const;
    const pt::ptime getbeginTime () const;
    const pt::ptime getendTime () const;
    const pt::ptime endRent () const;
};


#endif //CARRENTALPROJECT_RENT_H
