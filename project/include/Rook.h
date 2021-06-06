//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_ROOK_H
#define CHECKERS_ROOK_H

#include "typedefs.h"
#include "Field.h"
#include <Unit.h>

class Rook : public Unit {
public:
    Rook();
    virtual ~Rook();
    bool isMoveLegal(FieldPtr start,FieldPtr destination) override;
    bool isPromotionAvailable() override;
    char getUnitType() override;
};


#endif //CHECKERS_ROOK_H
