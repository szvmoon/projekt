//
// Created by student on 11.05.2021.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H

#include "typedefs.h"
#include "repositories/ClientRepository.h"
#include <vector>

class ClientManager {
private:
    ClientRepository clientRepository;
public:
    ClientPtr getClient(const std::string &personalId);
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string &personalId, AddressPtr address, ClientTypePtr clientType);
    void unregisterClient(ClientPtr &client);
    std::vector<ClientPtr> findClients(ClientPredicate);
    std::vector<ClientPtr> findAllClients();
};


#endif //CARRENTAL_CLIENTMANAGER_H
