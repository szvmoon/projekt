//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H


class Game {
public:
    virtual ~Game()=0;
    Game();
    void play();
    bool isOver();
};


#endif //CHECKERS_GAME_H
