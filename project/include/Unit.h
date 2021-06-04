//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_UNIT_H
#define CHECKERS_UNIT_H

#include <Field.h>
#include <typedefs.h>

class Unit {
public:
    Unit();
    virtual ~Unit()=0;
    virtual void move(FieldPtr start,FieldPtr destination);
    virtual bool isMoveLegal(FieldPtr start,FieldPtr destination);
};


#endif //CHECKERS_UNIT_H
