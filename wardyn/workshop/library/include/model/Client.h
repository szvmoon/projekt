//
// Created by student on 17.03.2021.
//

#ifndef CARRENTALPROJECT_CLIENT_H
#define CARRENTALPROJECT_CLIENT_H

#include <iostream>
#include "Address.h"
#include <vector>

using namespace std;
class Rent;
class Client
{
private:
    string firstName;
    string lastName;
    const string personalID;
    Address *address;
    vector<Rent*> currentRents;
public:
    Client(const string&,const string&,const string&, Address*);
    ~Client();
    const string getClientInfo () const;
    const string getfirstName () const;
    const string getlastName () const;
    const Address* getaddresspointer () const;
    const Rent* getRent(unsigned int& ) const;
    void setfirstName (const string&);
    void setlastName (const string&);
    void setaddresspointer (Address*);
    void Rent* setRent(unsigned int&, Rent*);
};

#endif //CARRENTALPROJECT_CLIENT_H
