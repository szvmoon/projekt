//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H

#include <string>
#include <vector>
#include "Unit.h"
#include <Board.h>
#include "typedefs.h"
#include "Checker.h"

class Player {
private:
    std::string name;
    std::vector<UnitPtr> units;
public:
    Player(const std::string &name);
    ~Player();
    UnitPtr getUnit(int id);
    const std::string &getName() const;



};



#endif //CHECKERS_PLAYER_H
