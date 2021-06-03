//
// Created by student on 03.06.2021.
//

#ifndef PROJECT_TEXTINTERFACE_H
#define PROJECT_TEXTINTERFACE_H


#include "Interface.h"
#include "Board.h"
#include "Field.h"
class TextInterface {
public:
    TextInterface();

    virtual ~TextInterface();

    static void displayBoard(BoardPtr board);
    virtual void move(FieldPtr start,FieldPtr destination);


};


#endif //PROJECT_TEXTINTERFACE_H
