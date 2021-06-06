//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_KING_H
#define CHECKERS_KING_H

#include "typedefs.h"
#include "Field.h"

class King : public Unit {
public:
    King();
    virtual ~King();
    bool isMoveLegal(FieldPtr start,FieldPtr destination) override;
    bool isPromotionAvailable() override;
    char getUnitType() override;
};


#endif //CHECKERS_KING_H
