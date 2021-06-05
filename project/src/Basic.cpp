
//
// Created by student on 03.06.2021.
//

#include "Basic.h"

Basic::Basic() {}

Basic::~Basic() {}

void Basic::play(PlayerPtr player1, PlayerPtr player2, BoardPtr board) {
    board->setUpPieces(board,player1,player2);
    TextInterface::displayBoard(board, player1, player2);
    int start_n, end_n;
    char start_c, end_c;
    std::cout << "Podaj pole startowe:" << std::endl;
    std::cin >> start_c >> start_n;
    std::cout << "Podaj pole koncowe:" << std::endl;
    std::cin >> end_c >> end_n;

    int jednostki=player2->countPlayerUnits();
    std::cout << jednostki << "\n";
    for (int i=1; i<=16; i++) {
        if(player2->getUnit(i) == board->getField(TextInterface::calculateField(start_c, start_n))->getUnit()){
            TextInterface::move(board->getField(TextInterface::calculateField(start_c,start_n)),board->getField(TextInterface::calculateField(end_c,end_n)));
            continue;
        } else {
            std::cout << "To nie jest twoja jednostka.";
            continue;
        }
    }

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

  // board->setUpPieces(board,player1,player2);
  //  TextInterface::displayBoard(board, player1, player2);
 //  if(board->getField(16)->getUnit()->isMoveLegal(board->getField(16),board->getField(23)))
   //TextInterface::move(board->getField(26),board->getField(23));
  //  TextInterface::displayBoard(board, player1, player2);

}

bool Basic::isOver(PlayerPtr player1, PlayerPtr player2) {
    if (player1->countPlayerUnits() == 0 || player2->countPlayerUnits() == 0) {
        return true;
    } else {
        return false;
    }
}
