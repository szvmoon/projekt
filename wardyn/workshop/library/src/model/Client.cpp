//
// Created by student on 17.03.2021.
//

#include "model/Client.h"
//#include "model/Address.h"
//#include <iostream>

using namespace std;

Client::Client(const string &firstName,const string &lastName,const string &personalID, Address *address) :firstName(firstName), lastName(lastName), personalID(personalID), address(address)
{

}
Client::~Client() {}
const string Client::getClientInfo () const
{
    return ("Client, "+firstName+", "+lastName+", "+personalID+", "+address->getAddressInfo());
}
const string Client::getFullClientInfo () const
{
    return (this->getClientInfo()+to_string(currentRents.size()));
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
/*const Rent* Client::getRent() const
{
    return currentRents.begin();
}*/
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
void Client::setRent(Rent* pointer)
{
    if (pointer != nullptr)
    {
        currentRents.push_back(pointer);
    }
}





