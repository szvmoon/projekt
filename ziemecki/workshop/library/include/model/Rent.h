//
// Created by student on 11.04.2021.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;;

class Client;
class Rent {
private:
    const int ID;
    Client *client;
    Vehicle *vehicle;

public:
    //Konstruktor desturktor
    Rent(int , Client *, Vehicle *);

    ~Rent();

    //Gettery

    const int get_ID() const;

    const Client *get_client() const;

    const Vehicle *get_vehicle() const;

    //Metody

    const std::string getRentInfo() const;



};


#endif //CARRENTAL_RENT_H
