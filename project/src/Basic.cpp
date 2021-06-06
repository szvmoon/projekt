
//
// Created by student on 03.06.2021.
//

#include "Basic.h"

Basic::Basic() {}

Basic::~Basic() {}

void Basic::play(PlayerPtr player1, PlayerPtr player2, BoardPtr board) {
    ///inicjalizacja gry
    board->setUpPieces(board,player1,player2);
    std::string name="test", start_field, end_field;
    int turn=3;
    bool isUnitYours=true;

  /*  ///Wstep do rozgrywki
    std::cout << "___________ROZPOCZECIE GRY___________\n";
    std::cout << "Gracz numer 1. Twoje jednostki sa czerwone. Podaj swoje imie:\n";
    std::cin >> name;
    player1->setName(name);
    std::cout << "Gracz numer 2. Twoje jednostki sa zolte. Podaj swoje imie:\n";
    std::cin >> name;
    player2->setName(name);
    std::cout << "Oto plansza gry, pierwszy ruch wykonuje Gracz 1.\n";*/

    ///glowny przebieg gry
    do {
        switch (turn) {
            case 1:
                if(board->getField(15)->getUnit()->isMoveLegal(board->getField(15),board->getField(24)))
                    TextInterface::move(board->getField(15),board->getField(24));
                TextInterface::displayBoard(board, player1, player2);
                ///pobranie pola startowego i koncowego
                std::cout << "Podaj pole, z ktorego jednostka chcesz ruszyc:\n";
                std::cin >> start_field;

                ///sprawdzenie czy podano wspolrzedne w poprawny sposob
                if (TextInterface::calculateField(start_field)==100) {
                    std::cout << "Podane wspolrzedne nie oznaczaja zadnego pola z planszy, podaj ponownie pole poczatkowe\n";
                    break;
                }
                std::cout << TextInterface::calculateField(start_field) << "\n";
                ///sprawdzenie czy poprawnie wybrano jednostke
                for (int i=1; i<=16; i++) {
                    if (player1->getUnit(i)->isAlive() && player1->getUnit(i) == board->getField(TextInterface::calculateField(start_field))->getUnit()) {
                        isUnitYours=true;
                        break;
                    } else if (i==16) {
                        isUnitYours=false;
                        break;
                    }
                }

                if (board->getField(TextInterface::calculateField(start_field))->getUnit()== nullptr) {
                    std::cout << "Na wybranym polu poczatkowym nie ma jednostki, podaj ponownie pole poczatkowe\n";
                    break;
                } else if (!isUnitYours) {
                    std::cout << "To nie jest twoja jednostka, podaj ponownie pole poczatkowe.\n";
                    break;
                }
                std::cout << "Podaj pole, na ktore chcesz ruszyc:\n";
                std::cin >> end_field;

                ///komunikaty o blednym polu koncowym
                while (TextInterface::calculateField(end_field)==100) {//end_c,end_n)) {
                    std::cout << "Podane wspolrzedne nie oznaczaja zadnego pola z planszy, podaj ponownie pole poczatkowe\n";
                    std::cout << "Podaj pole, na ktore chcesz ruszyc:\n";
                    std::cin >> end_field;
                }
                std::cout << TextInterface::calculateField(end_field) << "\n";
                while (!board->getField(TextInterface::calculateField(start_field))->getUnit()->isMoveLegal(board->getField(TextInterface::calculateField(start_field)), board->getField(TextInterface::calculateField(end_field)))) {
                    std::cout << "Ruch niedozwolony, podaj ponownie pole koncowe\n";
                    std::cout << "Podaj pole, na ktore chcesz ruszyc:\n";
                    std::cin >> end_field;
                }
                ///Wykonanie ruchu
                if (TextInterface::move(board->getField(TextInterface::calculateField(start_field)),
                                        board->getField(TextInterface::calculateField(end_field)))) {
                    std::cout << "Zbito jednostke przeciwnika.\n";
                }
                turn=3;
                break;

            case 2:
                ///pobranie pola startowego i koncowego
                std::cout << "Podaj pole, z ktorego jednostka chcesz ruszyc:\n";
                std::cin >> start_field;

                ///sprawdzenie czy podano wspolrzedne w poprawny sposob
                if (TextInterface::calculateField(start_field)==100) {
                    std::cout << "Podane wspolrzedne nie oznaczaja zadnego pola z planszy, podaj ponownie pole poczatkowe\n";
                    break;
                }

                ///sprawdzenie czy poprawnie wybrano jednostke
                for (int i=1; i<=16; i++) {
                    if (player2->getUnit(i)->isAlive() && player2->getUnit(i) == board->getField(TextInterface::calculateField(start_field))->getUnit()) {
                        isUnitYours=true;
                        break;
                    } else if (i==16) {
                        isUnitYours=false;
                        break;
                    }
                }

                if (board->getField(TextInterface::calculateField(start_field))->getUnit()== nullptr) {
                    std::cout << "Na wybranym polu poczatkowym nie ma jednostki, podaj ponownie pole poczatkowe\n";
                    break;
                } else if (!isUnitYours) {
                    std::cout << "To nie jest twoja jednostka, podaj ponownie pole poczatkowe.\n";
                    break;
                }
                std::cout << "Podaj pole, na ktore chcesz ruszyc:\n";
                std::cin >> end_field;

                ///komunikaty o blednym polu koncowym
                while (TextInterface::calculateField(end_field)==100) {//end_c,end_n)) {
                    std::cout << "Podane wspolrzedne nie oznaczaja zadnego pola z planszy, podaj ponownie pole poczatkowe\n";
                    std::cout << "Podaj pole, na ktore chcesz ruszyc:\n";
                    std::cin >> end_field;
                }
                while (!board->getField(TextInterface::calculateField(start_field))->getUnit()->isMoveLegal(board->getField(TextInterface::calculateField(start_field)), board->getField(TextInterface::calculateField(end_field)))) {
                    std::cout << "Ruch niedozwolony, podaj ponownie pole koncowe\n";
                    std::cout << "Podaj pole, na ktore chcesz ruszyc:\n";
                    std::cin >> end_field;
                }
                ///Wykonanie ruchu
                if (TextInterface::move(board->getField(TextInterface::calculateField(start_field)),
                                        board->getField(TextInterface::calculateField(end_field)))) {
                    std::cout << "Zbito jednostke przeciwnika.\n";
                }
                turn=3;
                break;

            case 3:
                TextInterface::displayBoard(board, player1, player2);
                std::cout << "Tura gracza " << player1->getName() << ".\n";
                turn=1;
                break;

            case 4:
                TextInterface::displayBoard(board, player1, player2);
                std::cout << "Tura gracza " << player2->getName() << ".\n";
                turn=2;
                break;
        }
    } while (!isOver(player1, player2));
}

bool Basic::isOver(PlayerPtr player1, PlayerPtr player2) {
    if (player1->countPlayerUnits() == 0 || player2->countPlayerUnits() == 0) {
        return true;
    } else {
        return false;
    }
}
