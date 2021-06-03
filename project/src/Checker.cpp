//
// Created by student on 03.06.2021.
//

#include "Checker.h"
#include <memory>

using namespace std;

Checker::Checker() {}

Checker::~Checker() {

}

void Checker::move(FieldPtr start, FieldPtr destination) {
    start->setUnit(nullptr);
    destination->setUnit(shared_from_this());
}
