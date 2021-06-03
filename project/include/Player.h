//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H

#include <string>
#include <vector>

class Player {
private:
    std::string name;

public:
    Player(const std::string &name);
    ~Player();
};


#endif //CHECKERS_PLAYER_H
