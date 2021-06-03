//
// Created by student on 03.06.2021.
//

#include "Basic.h"

Basic::Basic() {}

Basic::~Basic() {

}

void Basic::play(PlayerPtr player1, PlayerPtr player2, BoardPtr board) {
    int id=1;
    while  (!isOver()){
        TextInterface::displayBoard(board);
        switch (id) {
            case 1:

                TextInterface::move(board->getField(12),board->getField(19));

                break;
            case 2:
                break;
        }
    }
}

bool Basic::isOver() {
    return Game::isOver();
}
