//
// Created by student on 03.06.2021.
//


#include "Player.h"

Player::Player(const std::string &name) : name(name) {}

Player::~Player() {}

void Player::unitToPlayer1(BoardPtr board, UnitPtr unit) {
    for(int i=0; i<24;i++) {
        units.push_back(board->fields[i]->getUnit());
    }
}
void Player::unitToPlayer2(BoardPtr board, UnitPtr unit) {
    for(int i=48; i<=64;i++) {
        units.push_back(board->fields[i]->getUnit());
    }
}