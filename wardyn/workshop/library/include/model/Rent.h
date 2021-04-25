//
// Created by student on 06.04.2021.
//

#ifndef CARRENTALPROJECT_RENT_H
#define CARRENTALPROJECT_RENT_H
#include "model/Client.h"
#include "model/Vehicle.h"
#include <iostream>
#include <boost/date_time.hpp>
#include "typedefs.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;
class Client;
class Rent {
private:
    int id;
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    int rentCost=0;
public:
    Rent(const int &, ClientPtr, VehiclePtr, pt::ptime);
    ~Rent();
    string getRentInfo() const;
    int getid() const;
    const ClientPtr getclient() const;
    int getRentDays () const;
    const VehiclePtr getvehicle() const;
    pt::ptime getbeginTime () const;
    pt::ptime getendTime () const;
    void endRent (const pt::ptime&);
    int getRentCost () const;
};


#endif //CARRENTALPROJECT_RENT_H
