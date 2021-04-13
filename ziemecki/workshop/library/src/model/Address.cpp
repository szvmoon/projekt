//
// Created by student on 11.04.2021.
//

#include "model/Address.h"

using namespace std;

Address::Address(string bCity, string bStreet, string bNumber) : city(bCity), street(bStreet), number(bNumber) {}

Address::~Address() {}

string Address::get_City() const { return city; }

string Address::get_Street() const { return street; }

string Address::get_Number() const { return number; }

void Address::set_City(string tCity) { city = tCity; }

void Address::set_Street(string tStreet) { street = tStreet; }

void Address::set_Number(string tNumber) { number = tNumber; }

string Address::getAddressInfo() { return "Address " + city + " " + street + " " + number; }



