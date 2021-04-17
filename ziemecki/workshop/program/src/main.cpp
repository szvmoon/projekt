#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"


using namespace std;

int main() {
    Vehicle *C1 = new Vehicle("ELC12312", 20);
    Address *A1 = new Address("Wwa","Jasna","12");
    Client  *K1= new Client("Szymon", "Ziemecki","123123",A1);
    Rent *R1 = new Rent(1,K1,C1,pt::ptime(gr::date(2021,5,16)));
    R1->endRent(pt::ptime(gr::date(2021,5,17)));
    cout<<R1->getRentCost()<<endl;
    C1->set_basePrice(30);
    cout<<R1->getRentCost()<<endl;


    delete C1;
    delete A1;
    delete K1;
    delete R1;

    return 0;
}
