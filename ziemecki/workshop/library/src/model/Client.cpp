//
// Created by student on 23.03.2021.
//

#include "model/Client.h"
#include "model/Address.h"

using namespace std;

Client::Client(const string &name, const string &surname, const string &pid, Address *address) : firstName(name),
                                                                                                 lastName(surname),
                                                                                                 personalID(pid),
                                                                                                 address(address) {}

Client::~Client() {}


const string Client::getClientInfo() const {
    return("Client " + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo() + "\n");
}

const string Client::get_firstName() const { return firstName; }

const string Client::get_lastName() const { return lastName; }

const string Client::get_personalID() const { return personalID; }

const Address *Client::get_Address() const { return address; }

void Client::set_firstName(const string &name) {
    if (name != "")
        firstName = name;
}

void Client::set_lastName(const string &surname) {
    if (surname != "")
        lastName = surname;
}

void Client::set_Address(Address *nAddress) {
    if (nAddress != nullptr)
        address = nAddress;
}

void Client::add_Rent(Rent *ptr) {
    if (ptr != nullptr)
        currentRents.push_back(ptr);
}

const void Client::get_Rents() const {
    cout<<"Acutal Rents:"<<endl;
    for(int i=0;i<currentRents.size();i++) {
        cout<<currentRents[i]->getRentInfo();
    }
}

const void Client::getFullClientInfo() const {
    cout<<getClientInfo();
    get_Rents();
}
