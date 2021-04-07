//
// Created by student on 06.04.2021.
//

#include "model/Rent.h"
#include <string>
#include <iostream>

using namespace std;

Rent::Rent(int &id, Client *client, Vehicle *vehicle): id(id) , client(client), vehicle(vehicle)
{
    client.set
}
Rent::~Rent() {}
const string Rent::getRentInfo() const
{
    return ("Wypozyczenie: "+to_string(id)+", "+client->getClientInfo()+", "+vehicle->getVehicleInfo());
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