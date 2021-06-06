//
// Created by student on 03.06.2021.
//

#include "TextInterface.h"


TextInterface::TextInterface()  {}

TextInterface::~TextInterface() {}

void TextInterface::displayBoard(BoardPtr board, PlayerPtr player1, PlayerPtr player2) {
    std::cout << "    A  B  C  D  E  F  G  H   \n";
    std::cout << " ----------------------------\n";
    std::cout << " | ";
    for(int i=0; i<64;i++) {
        if (board->fields[i] != nullptr && board->fields[i]->getUnit() == nullptr /*&& */)
            std::cout << "[ ]";
        else if(board->fields[i]->getUnit() != nullptr) {
            for (int j=1; j<=16; j++) {
                if (board->fields[i]->getUnit() == player1->getUnit(j)) {
                    printf("\033[0;31m");
                    printf("[P]");
                    printf("\033[0m");
                } else if (board->fields[i]->getUnit() == player2->getUnit(j)) {
                    printf("\033[0;33m");
                    printf("[P]");
                    printf("\033[0m");
                } else if (!board->fields[i]->getUnit()->isAlive()){
                    std::cout << " . ";
                }
            }
        }

        if ((i + 1) % 8 == 0){
            std::cout << " | " << (i+1)/8 << std::endl;
            if(i!=63)
                std::cout << " | ";
        }
    }
    std::cout << " ----------------------------\n";
    std::cout << "    A  B  C  D  E  F  G  H   \n";

}
void TextInterface::move(FieldPtr start, FieldPtr destination) {
    if (destination->getUnit()!= nullptr) {
        destination->getUnit()->setAlive(false);
    }
    destination->setUnit(start->getUnit());
    start->setUnit(nullptr);
}

int TextInterface::calculateField(char &row, int &column) {
    int number=row;
    int fieldnr;
    if (number == 65) {
        fieldnr=column;
    } else if (number == 66) {
        fieldnr=8+column;
    } else if (number == 67) {
        fieldnr=16+column;
    } else if (number == 68) {
        fieldnr=24+column;
    } else if (number == 69) {
        fieldnr=32+column;
    } else if (number == 70) {
        fieldnr=40+column;
    } else if (number == 61) {
        fieldnr=48+column;
    } else {
        fieldnr=56+column;
    }
    return fieldnr;
}

