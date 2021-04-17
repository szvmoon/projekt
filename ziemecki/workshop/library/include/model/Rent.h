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
    int ID;
    Client *client;
    Vehicle *vehicle;
    pt::ptime beginTime = pt::not_a_date_time;
    pt::ptime endTime= pt::not_a_date_time;

public:
    //Konstruktor desturktor
    Rent(const int &, Client *, Vehicle *,const pt::ptime &);

    ~Rent();

    //Gettery

    const int& get_ID() const;

    const Client *get_client() const;

    Vehicle *const get_vehicle() const;

    const pt::ptime& get_beginDate() const;

    const pt::ptime& get_endDate() const;


    //Metody
    std::string getRentInfo() const;

    const int getRentDays() const;

    const int getRentCost() const;

    void endRent(const pt::ptime&);



};


#endif //CARRENTAL_RENT_H
