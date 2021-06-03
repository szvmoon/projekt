//
// Created by student on 03.06.2021.
//

#ifndef PROJECT_INTERFACE_H
#define PROJECT_INTERFACE_H

#include <iostream>
#include "Board.h"
#include "Field.h"
class Interface {
public:
    Interface();
    virtual ~Interface()=0;
    virtual void displayBoard(BoardPtr board);

};


#endif //PROJECT_INTERFACE_H
