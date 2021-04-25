//
// Created by student on 25.04.2021.
//

#ifndef CARRENTALPROJECT_CLIENTREPOSITORY_H
#define CARRENTALPROJECT_CLIENTREPOSITORY_H
#include "typedefs.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <model/Client.h>

class ClientRepository {
private:
    std::vector <ClientPtr> clientRepository;
public:
    ClientRepository();
    ~ClientRepository();
    ClientPtr get(const int &) const;
    void add(ClientPtr);
    void remove(ClientPtr);
    const std::string report() const;
    int size ();
};


#endif //CARRENTALPROJECT_CLIENTREPOSITORY_H
