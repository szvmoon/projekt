//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

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
    int size();
    std::vector<ClientPtr> findBy(ClientPredicate);
    std::vector<ClientPtr> findAll();
    ClientPtr findByPersonalId(const std::string &personalId) const;
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
