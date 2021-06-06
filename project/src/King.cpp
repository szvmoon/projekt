//
// Created by student on 03.06.2021.
//

#include "King.h"
#include <iostream>

using namespace std;

King::King() {}

King::~King() {

}

bool King::isMoveLegal(FieldPtr start, FieldPtr destination) {
    int startRow=calculateRow(start);
    int startCol=calculateCol(start);
    int destRow=calculateRow(destination);
    int destCol=calculateCol(destination);



}

bool King::isPromotionAvailable() {
    return false;
}

char King::getUnitType() {
    return 'K';
}
