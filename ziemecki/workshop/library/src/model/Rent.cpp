//
// Created by student on 11.04.2021.
//

#include "model/Rent.h"

using namespace std;

Rent::Rent(int id, Client *c, Vehicle *v) : ID(id), client(c), vehicle(v) {
    client->add_Rent(this);
}

Rent::~Rent() {}

const int Rent::get_ID() const { return ID; }

const Client *Rent::get_client() const { return client; }

const Vehicle *Rent::get_vehicle() const { return vehicle; }

const string Rent::getRentInfo() const {
    return(to_string(ID) + " " + client->get_firstName() + " " + client->get_lastName() + " " + vehicle->getVehicleInfo());
}

