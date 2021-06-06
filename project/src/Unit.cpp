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

bool Unit::isPromotionAvailable() {
    return false;
}

char Unit::getUnitType() {
    return 0;
}

int Unit::calculateRow(FieldPtr field) {
    int row;
    if(field->getNr()>=1 && field->getNr()<=8)
    {
        row=0;
    }
    else if(field->getNr()>=9 && field->getNr()<=16)
    {
        row=1;
    }
    else if(field->getNr()>=17 && field->getNr()<=24)
    {
        row=2;
    }
    else if(field->getNr()>=25 && field->getNr()<=32)
    {
        row=3;
    }
    else if(field->getNr()>=33 && field->getNr()<=40)
    {
        row=4;
    }
    else if(field->getNr()>=41 && field->getNr()<=48)
    {
        row=5;
    }
    else if(field->getNr()>=49 && field->getNr()<=56)
    {
        row=6;
    }
    else if(field->getNr()>=57 && field->getNr()<=64)
    {
        row=7;
    }

    return row;
}

int Unit::calculateCol(FieldPtr field) {
    int row;
    int col;
    if(field->getNr()>=1 && field->getNr()<=8)
    {
        row=0;
        col=field->getNr();
    }
    else if(field->getNr()>=9 && field->getNr()<=16)
    {
        row=1;
        col=field->getNr()-row*8;
    }
    else if(field->getNr()>=17 && field->getNr()<=24)
    {
        row=2;
        col=field->getNr()-row*8;
    }
    else if(field->getNr()>=25 && field->getNr()<=32)
    {
        row=3;
        col=field->getNr()-row*8;
    }
    else if(field->getNr()>=33 && field->getNr()<=40)
    {
        row=4;
        col=field->getNr()-row*8;
    }
    else if(field->getNr()>=41 && field->getNr()<=48)
    {
        row=5;
        col=field->getNr()-row*8;
    }
    else if(field->getNr()>=49 && field->getNr()<=56)
    {
        row=6;
        col=field->getNr()-row*8;
    }
    else if(field->getNr()>=57 && field->getNr()<=64)
    {
        row=7;
        col=field->getNr()-row*8;
    }
    return col-1;
}


