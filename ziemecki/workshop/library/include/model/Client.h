//
// Created by student on 23.03.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <iostream>
#include "model/Address.h"
#include "model/Rent.h"
#include <vector>


class Rent;
class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address *address;
    std::vector <Rent*> currentRents;

public:
    //konstruktor
    //lista inicjalizacyjna konstruktora
    Client(const std::string&, const std::string&, const std::string&, Address *);

    //destruktor
    ~Client();

    //gettery

    const std::string& get_firstName() const;

    const std::string& get_lastName() const;

    const std::string& get_personalID() const;

    const Address *get_Address() const;

    void get_Rents() const;

    //settery

    void set_firstName(const std::string&);

    void set_lastName(const std::string&);

    void set_Address(Address *);

    //metody/operacje klasy

    void add_Rent(Rent *);

    void getFullClientInfo() ;

    std::string getClientInfo() ;

};


#endif //CARRENTAL_CLIENT_H
