#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "repositories/StorageContainer.h"


using namespace std;

int main() {
    StorageContainerPtr S2 = make_shared<StorageContainer>();
    cout<<S2->getRentRepository()->report();
    cout<<S2->getClientRepository()->report();
    cout<<S2->getVehicleRepository()->report();

    ClientPtr K1 = make_shared<Client>("Szymon", "Ziemecki","123",nullptr);
    BicyclePtr V1 = make_shared<Bicycle>("ELC",20);
    RentPtr R1 = make_shared<Rent>(2, K1, V1, pt::second_clock::local_time());
    R1->endRent(pt::ptime(gr::date(2021,5,16)));

    S2->getRentRepository()->add(R1);

    cout<<S2->getRentRepository()->report();
    cout<<S2->getClientRepository()->report();
    cout<<S2->getVehicleRepository()->report();




    return 0;
}
