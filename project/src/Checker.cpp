//
// Created by student on 03.06.2021.
//

#include "Checker.h"
#include <memory>
#include <Board.h>
#include <cmath>

using namespace std;

Checker::Checker() {}

Checker::~Checker() {

}

void Checker::move(FieldPtr start, FieldPtr destination) {
    start->setUnit(nullptr);
    destination->setUnit(shared_from_this());
}

bool Checker::isMoveLegal(FieldPtr start, FieldPtr destination) {
    if(destination->getUnit() == nullptr && abs(destination->getNr()-start->getNr()) == 7 && abs(destination->getNr()-start->getNr())== 9)
        return true;
    else if(destination->getUnit() == nullptr && abs(destination->getNr()-start->getNr()) == 7 && Board::getFieldId(start))
        return  true;
    else if(destination->getUnit() == nullptr && abs(destination->getNr()-start->getNr()) == 7 && )
        return  true;

}
