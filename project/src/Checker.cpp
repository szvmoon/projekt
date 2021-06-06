//
// Created by student on 03.06.2021.
//
#include <iostream>
#include "Checker.h"
#include <memory>

using namespace std;

Checker::Checker() {}

Checker::~Checker() {}

bool Checker::isMoveLegal(FieldPtr start, FieldPtr destination) {


    if(abs(destination->getNr()-start->getNr()) == 7 || abs(destination->getNr()-start->getNr())== 9)
    {
        if(start->getNr()%8 != 0 && (start->getNr()+1)%8!=0) {
            cout << "legalny";
            return true;
        }

        if(abs(destination->getNr()-start->getNr()) == 9) {
            if(start->getNr()+1%8==0) {
                cout << "legalny";
                return true;
            }
        }
        if(abs(destination->getNr()-start->getNr()) == 7) {
            if(start->getNr()%8==0) {
                cout << "legalny";
                return true;
            }
        }
    }
    cout<<"nielegalny";
    return false;
}

bool Checker::isPromotionAvailable() {
    return true;
}

char Checker::getUnitType() {
    return 'C';
}
