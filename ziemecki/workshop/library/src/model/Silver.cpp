//
// Created by student on 27.04.2021.
//

#include "model/Silver.h"

int Silver::getMaxVehicles() {
    return 3;
}

std::string Silver::getTypeInfo() {
    return "Silver Client MaxRents: 3 Discount: 6";
}

double Silver::applyDiscount(double price) {
    return 6;

}
