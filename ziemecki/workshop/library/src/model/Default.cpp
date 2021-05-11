//
// Created by student on 27.04.2021.
//

#include "model/Default.h"

using namespace std;

int Default::getMaxVehicles() {
    return 1;
}

double Default::applyDiscount(double price) {
    return 0;
}

std::string Default::getTypeInfo() {
    return "Default Client MaxRents: 1 Discount: 0";
}
