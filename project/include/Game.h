//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H
#include <Board.h>
#include "TextInterface.h"


class Game {
public:

    Game();
    virtual ~Game()=0;
    virtual void play(PlayerPtr player1, PlayerPtr player2, BoardPtr board);
    virtual bool isOver();
};


#endif //CHECKERS_GAME_H
