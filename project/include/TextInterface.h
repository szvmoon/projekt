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

class TextInterface : public std::enable_shared_from_this<Checker>{
public:
    TextInterface();
    virtual ~TextInterface();
    static void displayBoard(BoardPtr board);
    static void move(FieldPtr start, FieldPtr destination);


};


#endif //PROJECT_TEXTINTERFACE_H
