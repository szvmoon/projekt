#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

using namespace std;

int main() {
    Address *A1 = new Address("Warszawa", "Jasna", "12");
    Client *K1 = new Client("Szymon", "Ziemecki", "1230", A1);
    Vehicle *C1 = new Vehicle("ELC123",12);
    Vehicle *C2 = new Vehicle("ELC1123",12);
    Rent *R1 = new Rent(1,K1,C1);
    Rent *R2 = new Rent(2,K1,C2);
    K1->getFullClientInfo();

    delete A1,K1,C1,C2,R1,R2;


    return 0;
}
