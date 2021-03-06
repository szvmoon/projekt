//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_CHECKER_H
#define CHECKERS_CHECKER_H

#include <Unit.h>
class Checker : public Unit , public std::enable_shared_from_this<Checker>{
public:
    Checker();
    virtual ~Checker();
    bool isMoveLegal(FieldPtr start,FieldPtr destination) override;
    bool isPromotionAvailable() override;
    char getUnitType() override;


};


#endif //CHECKERS_CHECKER_H
