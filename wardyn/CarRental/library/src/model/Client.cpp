//
// Created by student on 17.03.2021.
//

#include "model/Client.h"
#include <iostream>

using namespace std;

Client::Client(string firstName, string lastName, string personalID) :firstName(firstName), lastName(lastName), personalID(personalID) {}

Client::~Client() {}

string Client::getClientInfo () const
{
    return ("Client, "+firstName+", "+lastName+", "+personalID+"\n");
}
string Client::getfirstName()
{
    return (firstName);
}
string Client::getlastName()
{
    return (lastName);
}
void Client::setfirstName (string name)
{
    if (name != "")
    {
        firstName = name;
    }
}
void Client::setlastName(string surname)
{
    if (surname!="")
    {
        lastName = surname;
    }
}



