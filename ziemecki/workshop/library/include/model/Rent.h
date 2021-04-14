//
// Created by student on 11.04.2021.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/Client.h"
#include "model/Rent.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class Vehicle;

class Rent {
private:
    const int ID;
    Client *client;
    Vehicle *vehicle;
    pt::ptime beginTime = pt::not_a_date_time;
    pt::ptime endTime;

public:
    //Konstruktor desturktor
    Rent(int , Client *, Vehicle *,const pt::ptime &);

    ~Rent();

    //Gettery

    const int get_ID() const;

    const Client *get_client() const;

    const Vehicle *get_vehicle() const;

    pt::ptime get_beginDate();

    pt::ptime get_endDate();


    //Metody
    const std::string getRentInfo() const;

    int getRentDays();

    int getRentCost();

    void endRent(pt::ptime);



};


#endif //CARRENTAL_RENT_H
