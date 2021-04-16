//
// Created by student on 11.04.2021.
//

#include "model/Address.h"

using namespace std;

Address::Address(const string &bCity,const string &bStreet,const string &bNumber) : city(bCity), street(bStreet), number(bNumber) {}

Address::~Address() {}

const string& Address::get_City() const { return city; }

const string& Address::get_Street() const { return street; }

const string& Address::get_Number() const { return number; }

string Address::getAddressInfo() { return "Address " + city + " " + street + " " + number; }



