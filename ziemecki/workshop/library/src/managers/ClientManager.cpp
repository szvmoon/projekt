//
// Created by student on 11.05.2021.
//

#include "managers/ClientManager.h"

using namespace std;

ClientPtr ClientManager::getClient(const std::string &personalId) {
    return clientRepository.findByPersonalId(personalId);
}

ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName, const std::string &personalId,AddressPtr address, ClientTypePtr clientType) {
    ClientPtr client = clientRepository.findByPersonalId(personalId);
    if(client == nullptr)
    {
        ClientPtr newClient = std::make_shared<Client>(firstName, lastName, personalId, address, clientType);
        clientRepository.add(newClient);
        return newClient;
    }

    return client;

}

void ClientManager::unregisterClient(ClientPtr &client) {
    if(getClient(client->get_personalID()) != nullptr)
        client->setArchive(true);
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    auto function = [&](const ClientPtr &ptr) -> bool { return (predicate(ptr) && !ptr->isArchive());};
    return clientRepository.findBy(function);
}

std::vector<ClientPtr> ClientManager::findAllClients() {
    return findClients([](ClientPtr ptr){return ptr != nullptr;});
}


