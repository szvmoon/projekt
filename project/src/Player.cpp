//
// Created by student on 03.06.2021.
//


#include "Player.h"
#include <memory>
#include <King.h>


using namespace std;

Player::Player(const std::string &name) : name(name) {
    for(int i=0;i<16;i++)
    {
        UnitPtr unit = make_shared<King>();
        units.push_back(unit);
    }
}

Player::~Player() {}

UnitPtr Player::getUnit(int id) {
    return units[id-1];
}

const string &Player::getName() const {
    return name;
}

int Player::countPlayerUnits() const {
    int aliveunits=0;
    for (int i=0; i<=15; i++) {
        if (units[i]->isAlive()) {
            aliveunits+=1;
        }
    }
    return aliveunits;
}

void Player::setName(const string &name) {
    Player::name = name;
}






