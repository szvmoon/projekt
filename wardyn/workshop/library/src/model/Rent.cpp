//
// Created by student on 06.04.2021.
//

#include "model/Rent.h"
#include <string>
#include <iostream>
#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;

Rent::Rent(int &id, Client *client, Vehicle *vehicle, pt::ptime beginTime): id(id) , client(client), vehicle(vehicle), beginTime(beginTime)
{
    client->setRent(this);
    vehicle->setrented(true);
    if (beginTime == pt::not_a_date_time)
    {
        beginTime = pt::second_clock::local_time();
    }
}
Rent::~Rent() {}
const string Rent::getRentInfo() const
{
    return ("Wypozyczenie: "+to_string(id)+", "+client->getClientInfo()+", "+vehicle->getVehicleInfo()+to_simple_string(beginTime)+to_simple_string(endTime)+"\n");
}
const int Rent::getid() const
{
    return (id);
}
const Client* Rent::getclient() const
{
    return client;
}
const Vehicle* Rent::getvehicle() const
{
    return vehicle;
}

const pt::ptime Rent::getbeginTime() const
{
    return beginTime;
}
const pt::ptime Rent::getendTime() const
{
    return endTime;
}

const pt::ptime Rent::endRent() const
{
    pt::ptime endTime;
    if (endTime == pt::not_a_date_time)
    {
        endTime = pt::second_clock::local_time();
        if (endTime < beginTime)
        {
            endTime=beginTime;
        }
    }
    return endTime;
}
const string getRentDays() const
{
   string rentdays;
   if (endTime == pt::not_a_date_time)
   {
       rentdays="0";
   }
}
