//
// Created by student on 23.03.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <iostream>
#include "model/Address.h"
#include "model/ClientType.h"
#include "model/Rent.h"
#include "typedefs.h"
#include <sstream>
#include <vector>


class Rent;
class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive = false;
    //std::vector <RentPtr> currentRents;

public:
    //konstruktor
    //lista inicjalizacyjna konstruktora
    Client(const std::string&, const std::string&, const std::string&, AddressPtr, ClientTypePtr);
    Client(const std::string&, const std::string&, const std::string&, AddressPtr);
    //destruktor
    ~Client();

    //gettery

    const std::string& get_firstName() const;

    const std::string& get_lastName() const;

    const std::string& get_personalID() const;

    const AddressPtr get_Address() const;

    const bool isArchive() const;

    // std::string get_Rents();

    //settery

    const void set_firstName(const std::string&);

    const void set_lastName(const std::string&);

    const void set_Address(AddressPtr);

    const void setArchive(bool);

    //metody/operacje klasy

   // void add_Rent(RentPtr);

  //  void remove_Rent(RentPtr);

   // std::string getFullClientInfo();

    const std::string getClientInfo() ;

    void setClientType(ClientTypePtr);

    int getMaxVehicles();

    double applyDiscount(double);


};


#endif //CARRENTAL_CLIENT_H
