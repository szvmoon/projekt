//
// Created by student on 27.04.2021.
//

#include "model/Bronze.h"

std::string Bronze::getTypeInfo() {
    return "Bronze Client MaxRents: 2 Discount: 3";
}

int Bronze::getMaxVehicles() {
    return 2;
}

double Bronze::applyDiscount(double price) {
    return 3;
}
