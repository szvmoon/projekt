//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_FIELD_H
#define CHECKERS_FIELD_H

#include <Unit.h>
#include <memory>
#include <typedefs.h>

class Field {
private:
    UnitPtr unit=nullptr;
    int nr;
public:
    Field(int _nr);
    ~Field();
    void setUnit(UnitPtr _unit);
    int getNr() const;
    UnitPtr getUnit();

};


#endif //CHECKERS_FIELD_H
