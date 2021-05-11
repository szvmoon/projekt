//
// Created by student on 27.04.2021.
//

#include "model/Platinum.h"

int Platinum::getMaxVehicles() {
    return 5;
}

std::string Platinum::getTypeInfo() {
    return "Platinum Client MaxRents: 5 Discount: 10%";
}

double Platinum::applyDiscount(double price) {
    return price*0.1;
}
