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
        this->beginTime = pt::second_clock::local_time();
    }
}
Rent::~Rent() {}
string Rent::getRentInfo() const
{
    return ("Wypozyczenie: "+to_string(id)+", "+client->getClientInfo()+", "+vehicle->getVehicleInfo()+to_simple_string(beginTime)+to_simple_string(endTime)+"\n");
}
int Rent::getid() const
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

pt::ptime Rent::getbeginTime() const
{
    return beginTime;
}
pt::ptime Rent::getendTime() const
{
    return endTime;
}

void Rent::endRent(const pt::ptime &now)
{
    if (endTime == pt::not_a_date_time)
    {
        endTime=now;
        if (endTime < beginTime)
        {
            endTime = beginTime;
        }
    }
    vehicle->setrented(false);
    //this->client->currentRents.erase(remove(this->client->currentRents.begin, ));
    //return endTime;
    this->rentCost = (getRentDays() * this->vehicle->getbasePrice());
}
int Rent::getRentDays() const
{
    pt::time_period rentdays(beginTime, endTime);
    if (this->vehicle->getrented())
    {
        return 0;
    } else if (beginTime == endTime)
    {
        return 0;
    } else
    {
        return (rentdays.length().hours() / 24);
    }
}
int Rent::getRentCost() const
{
    return rentCost;
}
