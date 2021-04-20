//
// Created by student on 23.03.2021.
//

#include "model/Client.h"
#include "model/Address.h"

using namespace std;

Client::Client(const string &name, const string &surname, const string &pid, AddressPtr address) : firstName(name),
                                                                                                 lastName(surname),
                                                                                                 personalID(pid),
                                                                                                 address(address) {}

Client::~Client() {}


string Client::getClientInfo() {
    return("Client " + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo() + "\n");
}

const string& Client::get_firstName() const { return firstName; }

const string& Client::get_lastName() const { return lastName; }

const string& Client::get_personalID() const { return personalID; }

const AddressPtr Client::get_Address() const { return address; }

void Client::set_firstName(const string &name) {
    if (name != "")
        firstName = name;
}

void Client::set_lastName(const string &surname) {
    if (surname != "")
        lastName = surname;
}

void Client::set_Address(AddressPtr nAddress) {
    if (nAddress != nullptr)
        address = nAddress;
}

void Client::add_Rent(RentPtr ptr) {
    if (ptr != nullptr)
        currentRents.push_back(ptr);
}

string Client::get_Rents(){
    stringstream napis;
    napis << "Actual Rents:\n";
    for(int i=0;i<currentRents.size();i++) {
        napis << currentRents[i]->getRentInfo();
    }
    return napis.str();
}

string Client::getFullClientInfo() {
    stringstream napis;
    napis<<getClientInfo();
    napis<<get_Rents();
    return napis.str();
}

void Client::remove_Rent(RentPtr ptr) {
    currentRents.erase(std::remove(currentRents.begin(), currentRents.end(), ptr), currentRents.end());
}
