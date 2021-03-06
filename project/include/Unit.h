//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_UNIT_H
#define CHECKERS_UNIT_H

#include <Field.h>
#include <typedefs.h>

class Unit {
private:
    bool alive=true;
public:
    Unit();
    virtual ~Unit()=0;
    bool isAlive() const;
    void setAlive(bool alive);
    virtual bool isMoveLegal(FieldPtr start,FieldPtr destination);
    virtual bool isPromotionAvailable();
    virtual char getUnitType();
    int calculateRow(FieldPtr field);
    int calculateCol(FieldPtr field);
};


#endif //CHECKERS_UNIT_H
