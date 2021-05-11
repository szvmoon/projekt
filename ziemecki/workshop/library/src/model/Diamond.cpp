//
// Created by student on 27.04.2021.
//

#include "model/Diamond.h"

std::string Diamond::getTypeInfo() {
    return "Diamond Client MaxRents: 10 Discount: \nPrice < 125: 10%\nPrice < 250: 20%\nPrice <500: 30%\nPrice > 500: 40%";;
}

int Diamond::getMaxVehicles() {
    return 10;
}

double Diamond::applyDiscount(double price) {
    double multiplier;
    multiplier = price < 125 ? 0.1 :
                 price < 250 ? 0.2 :
                 price < 500 ? 0.3 :
                 price >= 500 ? 0.4 : 0;
    return price*multiplier;
}
