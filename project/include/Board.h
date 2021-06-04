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
    std::vector<FieldPtr> fields;
    void setUpPieces(BoardPtr board, PlayerPtr p1, PlayerPtr p2);
    int getFieldId(FieldPtr field);



};


#endif //CHECKERS_BOARD_H
