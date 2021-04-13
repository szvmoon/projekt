//
// Created by student on 11.04.2021.
//

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H

#include <iostream>

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:

    //Konstruktor i destruktor
    Address(std::string, std::string, std::string);

    ~Address();

    //Gettery
    std::string get_City() const;

    std::string get_Street() const;

    std::string get_Number() const;

    //Settery
    void set_City(std::string);

    void set_Street(std::string);

    void set_Number(std::string);

    //Metody
    std::string getAddressInfo();


};


#endif //CARRENTAL_ADDRESS_H
