//
// Created by student on 23.03.2021.
//

#include "model/Client.h"
#include <iostream>

using namespace std;

Client::Client(std::string name, std::string surname, std::string pid) : firstName(name), lastName(surname), personalID(pid)
{

}

Client::~Client()
{

}


string Client::getClientInfo() const
{
    return("Client " + firstName +" " + lastName + " " + personalID);
}

string Client::get_firstName() const {return firstName;}

string Client::get_lastName() const {return lastName;}

string Client::get_personalID() const {return personalID;}

void Client::set_firstName(string name)
{
    if(name != "")
    firstName=name;
}

void Client::set_lastName(string surname)
{
    if(surname != "")
    lastName=surname;
}
