//
// Created by student on 03.06.2021.
//

#include "Bishop.h"

Bishop::Bishop() {}

Bishop::~Bishop() {

}

bool Bishop::isMoveLegal(FieldPtr start, FieldPtr destination) {
    int row;
    int col;
    if(start->getNr()>=0 && start->getNr()<=7)
    {
        row=0;
        col=start->getNr();
    }
    else if(start->getNr()>=8 && start->getNr()<=15)
    {
        row=1;
        col=start->getNr()-row*8;
    }
    else if(start->getNr()>=16 && start->getNr()<=23)
    {
        row=2;
        col=start->getNr()-row*8;
    }
    else if(start->getNr()>=24 && start->getNr()<=31)
    {
        row=3;
        col=start->getNr()-row*8;
    }
    else if(start->getNr()>=32 && start->getNr()<=39)
    {
        row=4;
        col=start->getNr()-row*8;
    }
    else if(start->getNr()>=40 && start->getNr()<=47)
    {
        row=5;
        col=start->getNr()-row*8;
    }
    else if(start->getNr()>=48 && start->getNr()<=55)
    {
        row=6;
        col=start->getNr()-row*8;
    }
    else if(start->getNr()>=56 && start->getNr()<=63)
    {
        row=7;
        col=start->getNr()-row*8;
    }


}

bool Bishop::isPromotionAvailable() {
    return false;
}

char Bishop::getUnitType() {
    return 'B';
}
