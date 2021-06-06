//
// Created by student on 03.06.2021.
//

#include "TextInterface.h"


TextInterface::TextInterface()  {}

TextInterface::~TextInterface() {}

void TextInterface::displayBoard(BoardPtr board, PlayerPtr player1, PlayerPtr player2) {
    int row=1;
    std::cout << "    A  B  C  D  E  F  G  H   \n";
    std::cout << " ----------------------------\n";
    std::cout << " | ";
    for(int i=0; i<64;i++) {
        if (board->fields[i] != nullptr && board->fields[i]->getUnit() == nullptr /*&& */)
            std::cout << "[ ]";
        else if(board->fields[i]->getUnit() != nullptr) {
            for (int j=1; j<=16; j++) {
                if (board->fields[i]->getUnit() == player1->getUnit(j)) {
                    printf("[");
                    printf("\033[0;31m");
                    printf("P");
                    printf("\033[0m");
                    printf("]");

                } else if (board->fields[i]->getUnit() == player2->getUnit(j)) {
                    printf("[");
                    printf("\033[0;33m");
                    printf("P");
                    printf("\033[0m");
                    printf("]");

                } else if (!board->fields[i]->getUnit()->isAlive()){
                    std::cout << "[ ]";
                }
            }
        }

        if ((i + 1) % 8 == 0){
            std::cout << " | " << row << std::endl;
            row+=1;
            if(i!=63)
                std::cout << " | ";
        }
    }
    std::cout << " ----------------------------\n";
}
bool TextInterface::move(FieldPtr start, FieldPtr destination) {
    bool didKill=false;
    if (destination->getUnit()!= nullptr) {
        destination->getUnit()->setAlive(false);
        didKill=true;
    }
    destination->setUnit(start->getUnit());
    start->setUnit(nullptr);
    return didKill;
}

int TextInterface::calculateField(std::string &field) {
    int number =field[0];
    int row =field[1];
    int fieldnr;
    //std::cout << "dostałem number: " << number << " row; " << row << std::endl;
    if (number == 65) {number=1;}
    else if (number == 66) {number=2;}
    else if (number == 67) {number=3;}
    else if (number == 68) {number=4;}
    else if (number == 69) {number=5;}
    else if (number == 70) {number=6;}
    else if (number == 71) {number=7;}
    else if (number == 72) {number=8;}
    else {
        fieldnr=100;
        return fieldnr;
    }

    if (row == 49) {
        fieldnr=number;
    } else if (row == 50) {
        fieldnr=8+number;
    } else if (row == 51) {
        fieldnr=16+number;
    } else if (row == 52) {
        fieldnr=24+number;
    } else if (row == 53) {
        fieldnr=32+number;
    } else if (row == 54) {
        fieldnr=40+number;
    } else if (row == 55) {
        fieldnr=48+number;
    } else if (row == 56){
        fieldnr=56+number;
    } else {
        fieldnr=100;
        return fieldnr;
    }
    return fieldnr;
}

bool TextInterface::isFieldCorrect(std::string &field) {   //char &column, int &row) {
    bool isFieldCorrect=true;
    //std::cout << "dostałem char: " << column << ", int: " << row << std::endl;
    std::cout << "dostałem string: " << field << std::endl;
    char column =field[0];
    int row =field[1];
    std::cout << "dostałem column: " << column << " row; " << row << std::endl;

    for (int i=0; i<=8; i++) {
        if(column == 65+i) {
            break;
        } else if (i==8) {
            isFieldCorrect=false;
        }
    }
    for (int i=0; i<=8; i++) {
        if(row == 49+i) {
            break;
        } else if (i==8) {
            isFieldCorrect=false;
        }
    }
    if (isFieldCorrect){
        std::cout << "true zwracam\n";
    } else {
        std::cout << "false zwracam\n";

    }
    return isFieldCorrect;
}

