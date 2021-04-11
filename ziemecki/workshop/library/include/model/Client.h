//
// Created by student on 23.03.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>

class Client {
private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;
public:
    //konstruktor
    //lista inicjalizacyjna konstruktora
    Client(std::string name, std::string surname, std::string pid);

    //destruktor
    ~Client();

    //metody/operacje klasy
    std::string getClientInfo() const;

    //gettery

    std::string get_firstName() const;

    std::string get_lastName() const;

    std::string get_personalID() const;

    //settery

    void set_firstName(std::string);

    void set_lastName(std::string);
};


#endif //CARRENTAL_CLIENT_H
