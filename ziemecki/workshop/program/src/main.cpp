#include <iostream>
#include <boost/date_time.hpp>
#include "managers/LogicContainer.h"
#include "repositories/StorageContainer.h"
#include "model/Rent.h"
#include "model/Vehicle.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Default.h"
#include "typedefs.h"


using namespace std;

int main() {
    StorageContainerPtr S2 = make_shared<StorageContainer>();
    //cout<<S2->getRentRepository()->report();
    //cout<<S2->getClientRepository()->report();
    //cout<<S2->getVehicleRepository()->report();

    ClientPtr K1 = make_shared<Client>("Szymon", "Ziemecki","123",nullptr);
    BicyclePtr V1 = make_shared<Bicycle>("ELC",20);
    RentPtr R1 = make_shared<Rent>(2, K1, V1, pt::second_clock::local_time());
    R1->endRent(pt::ptime(gr::date(2021,5,16)));

    S2->getRentRepository()->add(R1);

    //cout<<S2->getRentRepository()->report();
    //cout<<S2->getClientRepository()->report();
    //cout<<S2->getVehicleRepository()->report();

    LogicContainerPtr logicContainer = std::make_shared<LogicContainer>();

    AddressPtr a1 = std::make_shared<Address>("Wwa", "Nowa", "22");
    AddressPtr a2 = std::make_shared<Address>("Ldz", "Stara", "25");
    AddressPtr a3 = std::make_shared<Address>("Krk", "Mloda", "137");

    VehiclePtr v1 = logicContainer->getVehicleManager().registerBicycle("ELC",100);
    VehiclePtr v2 = logicContainer->getVehicleManager().registerMoped("ELC2",150,400);
    VehiclePtr v3 = logicContainer->getVehicleManager().registerCar("ELC3",300,2000, B);

    ClientTypePtr defaultMember = std::make_shared<Default>();

    ClientPtr c1 = logicContainer->getClientManager().registerClient("sz", "zs", "123", a1,defaultMember);
    ClientPtr c2 = logicContainer->getClientManager().registerClient("szz", "zzs", "1233", a2,defaultMember);

    RentPtr r1 = logicContainer->getRentManager().rentVehicle(c1,v1,pt::second_clock::local_time());
    RentPtr r2 = logicContainer->getRentManager().rentVehicle(c2,v2,pt::second_clock::local_time());

    logicContainer->getRentManager().returnVehicle(v1);
    logicContainer->getRentManager().returnVehicle(v2);

    cout<< c1->getClientInfo() << " " << logicContainer->getRentManager().checkClientRentBalance(c1);






    return 0;
}
