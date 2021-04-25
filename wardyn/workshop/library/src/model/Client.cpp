//
// Created by student on 17.03.2021.
//

#include "model/Client.h"
#include "typedefs.h"

using namespace std;

Client::Client(const string &firstName,const string &lastName,const string &personalID, AddressPtr address) :firstName(firstName), lastName(lastName), personalID(personalID), address(address){}
Client::~Client() {}
string Client::getClientInfo () const
{
    return ("Client, "+firstName+", "+lastName+", "+personalID+", "+address->getAddressInfo());
}

string Client::getfirstName() const
{
    return (firstName);
}
string Client::getlastName() const
{
    return (lastName);
}
AddressPtr Client::getaddresspointer() const
{
    return address;
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
void Client::setRent(RentPtr pointer)
{
    if (pointer != nullptr)
    {
        currentRents.push_back(pointer);
    }
}
void Client::getRent() const
{
    cout << "Current Rents:" << endl;
    for (int i=0; i<=currentRents.size(); i++)
    {
        cout << currentRents[i]->getRentInfo();
    }
}
void Client::getFullClientInfo () const
{
    cout << getClientInfo();
    getRent();
}



