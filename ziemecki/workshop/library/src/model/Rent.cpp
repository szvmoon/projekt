//
// Created by student on 11.04.2021.
//

#include "model/Rent.h"

using namespace std;

Rent::Rent(const int &id, ClientPtr c, VehiclePtr v, const pt::ptime &beginT) : ID(id), client(c), vehicle(v),
                                                                        beginTime(beginT) {
    client->add_Rent(this);
    if (beginT == pt::not_a_date_time) {
        beginTime = pt::second_clock::local_time();
    } else {
        beginTime = beginTime;
    }
    endTime = pt::not_a_date_time;
    vehicle->set_RentStatus(true);
}

Rent::~Rent() {}

const int& Rent::get_ID() const { return ID; }

const ClientPtr Rent::get_client() const { return client; }

VehiclePtr const Rent::get_vehicle() const { return vehicle; }

string Rent::getRentInfo() const  {
    stringstream beginT;
    stringstream endT;
    beginT << beginTime;
    endT << endTime;
    return (to_string(ID) + " " + client->get_firstName() + " " + client->get_lastName() + " " +
            vehicle->getVehicleInfo() + " " + beginT.str() + " " +  endT.str() +  "\n") ;
}

const int Rent::getRentDays() const{
    pt::time_period period(beginTime, endTime);
    if (this->vehicle->isRented())
        return 0;

    else if (beginTime == endTime)
        return 0;

    else
        return 1+ (period.length().hours() / 24);

}

const int Rent::getRentCost() const{
    return (getRentDays() * this->vehicle->get_basePrice());
}

void Rent::endRent(const pt::ptime &now) {
    endTime=now;
    this->vehicle->set_RentStatus(false);
    client->remove_Rent(this);
}

const pt::ptime& Rent::get_beginDate() const { return beginTime; }

const pt::ptime& Rent::get_endDate() const { return endTime; }



