//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H

#include <vector>
#include <typedefs.h>


class Board {
private:

public:
    Board();
    ~Board();
    FieldPtr getField(int id);
    static void displayBoard();

    std::vector<FieldPtr> fields;


};


#endif //CHECKERS_BOARD_H
