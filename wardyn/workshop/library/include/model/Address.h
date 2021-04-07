//
// Created by student on 03.04.2021.
//

#ifndef CARRENTALPROJECT_ADDRESS_H
#define CARRENTALPROJECT_ADDRESS_H

#include <iostream>

using namespace std;

class Address
{
private:
    string city;
    string street;
    string number;
public:
    Address(const string&,const string&,const string&);
    ~Address();
    const string getAddressInfo () const;
    const string getcity () const;
    const string getstreet () const;
    const string getnumber () const;
    void setcity (string);
    void setstreet (string);
    void setnumber (string);
};
#endif //CARRENTALPROJECT_ADDRESS_H
