//
// Created by student on 11.04.2021.
//

#include "model/Rent.h"

using namespace std;

Rent::Rent(int id, Client *c, Vehicle *v, const pt::ptime &beginTime) : ID(id), client(c), vehicle(v),
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

const int Rent::get_ID() const { return ID; }

const Client *Rent::get_client() const { return client; }

const Vehicle *Rent::get_vehicle() const { return vehicle; }

const string Rent::getRentInfo() const {
    return (to_string(ID) + " " + client->get_firstName() + " " + client->get_lastName() + " " +
            vehicle->getVehicleInfo());
}

int Rent::getRentDays() {
    int daysOfRental;
    pt::time_period period(beginTime, endTime);
    if (this->vehicle->isRented() == true)
        return 0;

    else if (beginTime == endTime)
        return 0;

    else
        return (period.length().hours() / 24);

}

int Rent::getRentCost() {
    return (getRentDays() * this->vehicle->get_basePrice());
}

void Rent::endRent(pt::ptime now) {
    if (endTime.is_not_a_date_time()) {
        this->endTime = pt::second_clock::local_time();
    } else {
        this->endTime = now;
    }
    this->vehicle->set_RentStatus(false);
}

pt::ptime Rent::get_beginDate() { return beginTime; }

pt::ptime Rent::get_endDate() { return endTime; }



