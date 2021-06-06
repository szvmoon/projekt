//
// Created by student on 03.06.2021.
//

#include "Rook.h"

Rook::Rook() {}

Rook::~Rook() {

}

bool Rook::isMoveLegal(FieldPtr start, FieldPtr destination) {

}

bool Rook::isPromotionAvailable() {
    return false;
}

char Rook::getUnitType() {
    return 'R';
}
