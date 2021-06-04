//
// Created by student on 03.06.2021.
//
#include <iostream>
#include "Unit.h"

Unit::Unit() {}

Unit::~Unit() {}

bool Unit::isAlive() const {
    return alive;
}

void Unit::setAlive(bool alive) {
    Unit::alive = alive;
}

bool Unit::isMoveLegal(FieldPtr start, FieldPtr destination) {
    return false;
}

