//
// Created by student on 17.03.2021.
//

#ifndef CARRENTALPROJECT_CLIENT_H
#define CARRENTALPROJECT_CLIENT_H

#include <iostream>
#include "Address.h"
#include "Rent.h"
#include <vector>
#include "typedefs.h"

using namespace std;
class Rent;
class Client
{
private:
    string firstName;
    string lastName;
    const string personalID;
    AddressPtr address;

public:
    Client(const string&,const string&,const string&, Address*);
    ~Client();
    string getClientInfo () const;
    void getFullClientInfo () const;
    string getfirstName () const;
    string getlastName () const;
    AddressPtr getaddresspointer () const;
    void getRent() const;

    void setfirstName (const string&);
    void setlastName (const string&);
    void setaddresspointer (Address*);
    void setRent(RentPtr);
    void removeRent(RentPtr);


    vector<RentPtr> currentRents;
};

#endif //CARRENTALPROJECT_CLIENT_H
