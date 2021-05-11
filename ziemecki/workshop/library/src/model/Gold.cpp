//
// Created by student on 27.04.2021.
//

#include "model/Gold.h"

std::string Gold::getTypeInfo() {
    return "Gold Client MaxRents: 4 Discount: 5%";
}

int Gold::getMaxVehicles() {
    return 4;
}

double Gold::applyDiscount(double price) {
    return price*0.05;
}
