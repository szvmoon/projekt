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

int ClientRepository::size(std::vector<ClientPtr> v) {return v.size();}
