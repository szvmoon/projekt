
//
// Created by student on 03.06.2021.
//

#include "Basic.h"

Basic::Basic() {}

Basic::~Basic() {}

void Basic::play(PlayerPtr player1, PlayerPtr player2, BoardPtr board) {
        board->setUpPieces(board,player1,player2);
        TextInterface::displayBoard(board, player1, player2);

        int jednostki=player2->countPlayerUnits();
        std::cout << jednostki << "\n";

        TextInterface::move(board->getField(12),board->getField(52));

        for (int i=1; i<=16; i++) {
            if (!player2->getUnit(i)->isAlive()) {
                std::cout << "Jednostka o id " << i << " jest martwa,dziala" << std::endl;
            }
        }

        TextInterface::displayBoard(board, player1, player2);

        jednostki=player2->countPlayerUnits();
        std::cout << jednostki << "\n";

        for (int i=1; i<=16; i++) {
            player2->getUnit(i)->setAlive(false);
        }

        bool koniec = isOver(player1,player2);
        if (koniec) {
            std::cout << "koniec gry";
        }
        //basic.cpp z tego co pisał szymon sb sprawdzał
   /*
        board->setUpPieces(board,player1,player2);
        TextInterface::displayBoard(board);
        if(board->getField(9)->getUnit()->isMoveLegal(board->getField(9),board->getField(15)))
            TextInterface::move(board->getField(9),board->getField(15));
              TextInterface::displayBoard(board);*/

}

bool Basic::isOver(PlayerPtr player1, PlayerPtr player2) {
    if (player1->countPlayerUnits() == 0 || player2->countPlayerUnits() == 0) {
        return true;
    } else {
        return false;
    }
}
