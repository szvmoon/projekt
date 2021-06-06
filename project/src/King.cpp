//
// Created by student on 03.06.2021.
//

#include "King.h"
#include <iostream>

using namespace std;

King::King() {}

King::~King() {

}

bool King::isMoveLegal(FieldPtr start, FieldPtr destination) {
    int startRow=calculateRow(start);
    int startCol=calculateCol(start);
    int destRow=calculateRow(destination);
    int destCol=calculateCol(destination);
    int x,y; // 0,-1
        x=startRow-destRow;
        y=destCol-startCol;
        cout<<"start "<<startRow<< " "<< startCol<<endl;
        cout<<"Dest "<<destRow<< " "<< destCol<<endl;
        cout<<"OFFSET"<< x<<" " <<y<<endl;
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(x==i && y==j) {
                    cout << "Legalny";
                    return true;
                }
            }
        }


    cout<<"Nielegalny";
    return false;

}

bool King::isPromotionAvailable() {
    return false;
}

char King::getUnitType() {
    return 'K';
}
