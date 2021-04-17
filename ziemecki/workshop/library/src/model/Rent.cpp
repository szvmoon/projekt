//
// Created by student on 11.04.2021.
//

#include "model/Rent.h"

using namespace std;

Rent::Rent(const int &id, Client *c, Vehicle *v, const pt::ptime &beginTime) : ID(id), client(c), vehicle(v),
                                                                        beginTime(beginTime) {
    client->add_Rent(this);
    if (beginTime.is_not_a_date_time()) {
        this->beginTime = pt::second_clock::local_time();
    } else {
        this->beginTime = beginTime;
    }
    this->endTime = pt::not_a_date_time;
    vehicle->set_RentStatus(true);
}

Rent::~Rent() {}

const int& Rent::get_ID() const { return ID; }

const Client *Rent::get_client() const { return client; }

Vehicle *const Rent::get_vehicle() const { return vehicle; }

string Rent::getRentInfo() const  {
    return (to_string(ID) + " " + client->get_firstName() + " " + client->get_lastName() + " " +
            vehicle->getVehicleInfo());
}

const int Rent::getRentDays() const{
    pt::time_period period(beginTime, endTime);
    if (this->vehicle->isRented())
        return 0;

    else if (beginTime == endTime)
        return 0;

    else
        return (period.length().hours() / 24);

}

const int Rent::getRentCost() const{
    return (getRentDays() * this->vehicle->get_basePrice());
}

void Rent::endRent(const pt::ptime &now) {
    endTime=now;
    this->vehicle->set_RentStatus(false);
}

const pt::ptime& Rent::get_beginDate() const { return beginTime; }

const pt::ptime& Rent::get_endDate() const { return endTime; }



