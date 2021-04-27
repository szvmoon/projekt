//
// Created by student on 27.04.2021.
//

#include "model/Default.h"

int Default::getMaxVehicles() {
    return 1;
}

double Default::applyDiscount() {
    return 0;
}

std::string Default::getTypeInfo() {
    return "Default MaxRents: 1 Discount: 0"
}
