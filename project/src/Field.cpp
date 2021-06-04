//
// Created by student on 03.06.2021.
//

#include "Field.h"
#include <Unit.h>
#include <typedefs.h>

Field::Field(int _nr) : nr(_nr){}

Field::~Field() {

}

int Field::getNr() const {
    return nr;
}

void Field::setUnit(UnitPtr _unit) {
    unit = _unit;
}

UnitPtr Field::getUnit() {
    return unit;
}

void Field::setNr(int _nr) {
    nr=_nr

}

