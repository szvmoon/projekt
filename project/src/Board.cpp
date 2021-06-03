//
// Created by student on 03.06.2021.
//

#include "Board.h"
#include "Field.h"
#include <Checker.h>
#include <iostream>
#include "typedefs.h"
#include <string>

using namespace std;

Board::Board() {
    for(int i=0; i<=64;i++)
    {
        FieldPtr field = make_shared<Field>(i);
        fields.push_back(field);
    }

}

Board::~Board() {

}


FieldPtr Board::getField(int id) {
    return fields[id-1];
}

void Board::displayBoard() {
    cout << "  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n";
    cout << " ----------------------------\n";
    cout << " | ";
    for(int i=0; i<64;i++) {
        if (fields[i] != nullptr && fields[i]->getUnit() == nullptr)
            cout << " . ";
        else if(fields[i]->getUnit() != nullptr)
            cout<<" P ";

        if ((i + 1) % 8 == 0){
            cout << " | ";
            cout << endl;
            if(i!=63)
            cout << " | ";
    }
}
    cout << " ----------------------------\n";
}
