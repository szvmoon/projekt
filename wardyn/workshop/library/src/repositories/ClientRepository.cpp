//
// Created by student on 25.04.2021.
//

#include "../../repositories/ClientRepository.h"

using namespace std;

ClientRepository::ClientRepository() {}
ClientRepository::~ClientRepository() {}
ClientPtr ClientRepository::get (const int &id) const {
    if (id < 0 || clientRepository.size()) {
        return nullptr;
    } else {
        return clientRepository[id];
    }
}
void ClientRepository::add (ClientPtr newClient){
    if (newClient != nullptr){
        clientRepository.push_back(newClient);
    }
}
void ClientRepository::remove (ClientPtr to_remove){
    if(to_remove!=nullptr)
        clientRepository.erase(std::remove(clientRepository.begin(), clientRepository.end(), to_remove), clientRepository.end());
}
const string ClientRepository::report () const {
    stringstream allclients;
    for (int i=0; i<=clientRepository.size(); i++){
        allclients << clientRepository[i]->getClientInfo();
    }
    return allclients.str();
}
 int ClientRepository::size () {
    return clientRepository.size();
}
vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    vector<ClientPtr> found;
    for (unsigned int i=0; i<clientRepository.size(); i++) {
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