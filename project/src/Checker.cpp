//
// Created by student on 03.06.2021.
//

#include "Checker.h"
#include <memory>
#include <Board.h>
#include <cmath>
#include <iostream>

using namespace std;

Checker::Checker() {}

Checker::~Checker() {

}

void Checker::move(FieldPtr start, FieldPtr destination) {
    start->setUnit(nullptr);
    destination->setUnit(shared_from_this());
}

bool Checker::isMoveLegal(FieldPtr start, FieldPtr destination) {
    if(abs(destination->getNr()-start->getNr()) == 7 || abs(destination->getNr()-start->getNr())== 9)
    {
        if(start->getNr()%8 != 0 && (start->getNr()+1)%8!=0) {
            cout << "legalny";
            return true;
        }

        if(start->getNr()%8 == 0 || (start->getNr()+1)%8==0 && abs(destination->getNr()-start->getNr()) == 7) {
            cout << "legalny";
            return true;
        }
    }
    cout<<"nielegalny";
    return false;


}
