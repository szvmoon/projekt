//
// Created by student on 17.03.2021.
//

#include "model/Client.h"
//#include "model/Address.h"
//#include <iostream>

using namespace std;

Client::Client(const string &firstName,const string &lastName,const string &personalID, Address *address) :firstName(firstName), lastName(lastName), personalID(personalID), address(address)
{
    Client.setRent(this);
}
Client::~Client() {}
const string Client::getClientInfo () const
{
    return ("Client, "+firstName+", "+lastName+", "+personalID+", "+address->getAddressInfo()+"\n");
}
const string Client::getfirstName() const
{
    return (firstName);
}
const string Client::getlastName() const
{
    return (lastName);
}
const Address* Client::getaddresspointer() const
{
    return address;
}
const Rent* Client::getRent(unsigned int &i) const
{
    return currentRents[i];
}
void Client::setfirstName (const string &name)
{
    if (name != "")
    {
        firstName = name;
    }
}
void Client::setlastName(const string &surname)
{
    if (surname!="")
    {
        lastName = surname;
    }
}
void Client::setaddresspointer( Address* pointer)
{
    if (pointer != nullptr)
    {
        address = pointer;
    }
}
int Client::setRent(unsigned int &i, Rent* pointer)
{
    if (pointer != nullptr)
    {
        currentRents[i]=pointer;
    }
}





