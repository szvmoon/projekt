//
// Created by student on 03.06.2021.
//

#include "TextInterface.h"


TextInterface::TextInterface() {}

TextInterface::~TextInterface() {}

void TextInterface::displayBoard(BoardPtr board) {
    std::cout << "  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n";
    std::cout << " ----------------------------\n";
    std::cout << " | ";
    for(int i=0; i<64;i++) {
        if (board->fields[i] != nullptr && board->fields[i]->getUnit() == nullptr)
            std::cout << " . ";
        else if(board->fields[i]->getUnit() != nullptr)
            std::cout<<" P ";

        if ((i + 1) % 8 == 0){
            std::cout << " | ";
            std::cout << std::endl;
            if(i!=63)
                std::cout << " | ";
        }
    }
    std::cout << " ----------------------------\n";
}
void TextInterface::move(FieldPtr start, FieldPtr destination) {
    destination->setUnit(start->getUnit());
    start->setUnit(nullptr);
}

