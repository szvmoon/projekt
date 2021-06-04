//
// Created by student on 03.06.2021.
//


#include "Player.h"
#include <memory>


using namespace std;

Player::Player(const std::string &name) : name(name) {
    for(int i=0;i<16;i++)
    {
        UnitPtr unit = make_shared<Checker>();
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




