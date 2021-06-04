//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_BASIC_H
#define CHECKERS_BASIC_H


#include "Game.h"
#include "TextInterface.h"

class Basic : public Game {
public:
    Basic();

    virtual ~Basic();

    void play(PlayerPtr player1, PlayerPtr player2, BoardPtr board) override;

    bool isOver() override;

};


#endif //CHECKERS_BASIC_H
