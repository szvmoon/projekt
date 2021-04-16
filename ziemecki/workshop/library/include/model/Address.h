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
    Address(const std::string&,const std::string&,const std::string&);

    ~Address();

    //Gettery
    const std::string& get_City() const;

    const std::string& get_Street() const;

    const std::string& get_Number() const;

    //Settery


    //Metody
    std::string getAddressInfo() ;


};


#endif //CARRENTAL_ADDRESS_H
