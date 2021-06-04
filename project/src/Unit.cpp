//
// Created by student on 03.06.2021.
//
#include <iostream>
#include "Unit.h"

Unit::Unit(/*bool alive): alive(alive*/) {
    /*alive=true;*/
}

Unit::~Unit() {

}

bool Unit::isAlive() const {
    return alive;
}

void Unit::setAlive(bool alive) {
    Unit::alive = alive;
}



