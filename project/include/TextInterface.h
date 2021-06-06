//
// Created by student on 03.06.2021.
//

#ifndef PROJECT_TEXTINTERFACE_H
#define PROJECT_TEXTINTERFACE_H


#include "Interface.h"
#include "Player.h"
#include "Board.h"
#include "Field.h"
#include <memory>
#include <stdlib.h>

class TextInterface : public std::enable_shared_from_this<Checker>{
public:
    TextInterface();
    virtual ~TextInterface();
    static void displayBoard(BoardPtr board, PlayerPtr player1, PlayerPtr player2);
    static bool move(FieldPtr start, FieldPtr destination);
    static int calculateField(std::string &field);
    static bool isFieldCorrect(std::string &field/*char &column, int &row*/);


};


#endif //PROJECT_TEXTINTERFACE_H
