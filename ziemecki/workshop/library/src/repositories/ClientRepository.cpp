//
// Created by student on 18.04.2021.
//

#include "repositories/ClientRepository.h"

using namespace std;

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {}

ClientPtr ClientRepository::get(const int &index) const {
    if(index < 0 || index > clientRepository.size())
        return nullptr;
    else
        return clientRepository[index];
}

void ClientRepository::add(ClientPtr ptr) {
    if(ptr!=nullptr)
        clientRepository.push_back(ptr);
}

void ClientRepository::remove(ClientPtr ptr){
    if(ptr!=nullptr)
        clientRepository.erase(std::remove(clientRepository.begin(), clientRepository.end(), ptr), clientRepository.end());

}

const std::string ClientRepository::report() const {
    stringstream napis;

    for(int i=0; i<clientRepository.size();i++)
    {
        napis << clientRepository[i]->getClientInfo();
    }

    return napis.str();
}

int ClientRepository::size() {return clientRepository.size();}

vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) {
    vector<ClientPtr> found;
    for (unsigned int i = 0; i < clientRepository.size(); i++) {
        ClientPtr client = get(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() {
    return findBy([](ClientPtr ptr){return ptr != nullptr;});
}
