#include <iostream>
#include <model/Client.h>
#include "math_helpers.h"

using namespace std;

int main ()
{
    Client c1("jacek", "jackowski","694202137");
    Client *c2 = new Client("kamil","kamilek","9");
    cout << endl;
    cout << c1.getClientInfo();
    cout << c2->getClientInfo();
    cout << endl;
    c1.setfirstName("Pamela");
    c1.setlastName("Jablczan");
    cout << c1.getClientInfo();

    delete c2;
}
