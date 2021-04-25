//
// Created by student on 03.04.2021.
//

#include "model/Address.h"
#include <iostream>

using namespace std;

Address::Address(const string &city,const string &street,const string &number) :city(city), street(street), number(number) {}

Address::~Address() {}

string Address::getAddressInfo () const
{
    return ("Adres: "+city+", "+street+", "+number);
}
string Address::getcity() const
{
    return (city);
}
string Address::getstreet() const
{
    return (street);
}
string Address::getnumber() const
{
    return (number);
}
/*void Address::setcity (string newcity)
{
    if (newcity != "")
    {
        city = newcity;
    }
}
void Address::setstreet (string newstreet)
{
    if (newstreet != "")
    {
        street = newstreet;
    }
}
void Address::setnumber (string newnumber)
{
    if (newnumber != "")
    {
        number = newnumber;
    }
}*/