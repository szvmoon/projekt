//
// Created by student on 03.06.2021.
//

#include "Board.h"
#include "Field.h"
#include <Checker.h>
#include <iostream>
#include <Player.h>
#include "typedefs.h"
#include <string>

using namespace std;

Board::Board() {
    for(int i=0; i<=64;i++)
    {
        FieldPtr field = make_shared<Field>(i);
        fields.push_back(field);
    }

}

Board::~Board() {

}


FieldPtr Board::getField(int id) {
    return fields[id-1];
}

void Board::setUpPieces(BoardPtr board, PlayerPtr p1, PlayerPtr p2) {
    for(int i=0;i<16;i++){
        board->getField(i)->setUnit(p1->getUnit(i));
        board->getField(63-i)->setUnit(p2->getUnit(i));
    }

};




