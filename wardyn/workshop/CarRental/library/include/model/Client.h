//
// Created by student on 17.03.2021.
//

#ifndef CARRENTALPROJECT_CLIENT_H
#define CARRENTALPROJECT_CLIENT_H

#include <iostream>
#include <sstream>
using namespace std;

class Client
{
private:
    string firstName;
    string lastName;
    const string personalID;
public:
    //Client();
    Client(string, string, string);
    ~Client();
    string getClientInfo () const;
    void setClientInfo (string, string);
};

#endif //CARRENTALPROJECT_CLIENT_H
