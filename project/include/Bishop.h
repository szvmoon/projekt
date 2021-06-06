//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_BISHOP_H
#define CHECKERS_BISHOP_H

#include "typedefs.h"
#include "Field.h"
#include "Unit.h"


class Bishop : public Unit {
public:
    Bishop();
    virtual ~Bishop();
    bool isMoveLegal(FieldPtr start,FieldPtr destination) override;
    bool isPromotionAvailable() override;
    char getUnitType() override;
};


#endif //CHECKERS_BISHOP_H
