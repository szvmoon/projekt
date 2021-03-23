//
// Created by student on 17.03.2021.
//

#include "model/Client.h"
#include <iostream>

using namespace std;

/*Client::Client()
{
    cout << "Konstruktor zostal wywolany." << endl;
}*/

Client::Client(string firstName, string lastName, string personalID) :firstName(firstName), lastName(lastName), personalID(personalID) {}

Client::~Client() {}

string Client::getClientInfo () const
{
    return ("Client, "+firstName+", "+lastName+", "+personalID+"\n");
}

void Client::setClientInfo (string name, string surname)
{
    if (name != "")
    {
        firstName = name;
    }
    if (surname!="")
    {
        lastName = surname;
    }
}

