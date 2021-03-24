#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client klient1("Szymon", "Ziemecki", "12312");
    Client *klient2 = new Client("Dominik", "Ziemecki", "12312");
    cout << klient1.getClientInfo() << endl;
    klient1.set_firstName("Simano");
    cout << klient1.getClientInfo() << endl;
    cout << klient2->getClientInfo() << endl;
    delete klient2;
    return 0;
}
