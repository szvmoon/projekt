//
// Created by student on 03.06.2021.
//

#ifndef CHECKERS_TYPEDEFS_H
#define CHECKERS_TYPEDEFS_H

#include <memory>
#include <functional>

class Basic;
class Bishop;
class Board;
class Checker;
class Field;
class Game;
class King;
class Player;
class Rook;
class Timed;
class Unit;

typedef std::shared_ptr<Basic> BasicPtr;
typedef std::shared_ptr<Bishop> BishopPtr;
typedef std::shared_ptr<Board> BoardPtr;
typedef std::shared_ptr<Checker> CheckerPtr;
typedef std::shared_ptr<Field> FieldPtr;
typedef std::shared_ptr<Game> GamePtr;
typedef std::shared_ptr<King> KingPtr;
typedef std::shared_ptr<Player> PlayerPtr;
typedef std::shared_ptr<Rook> RookPtr;
typedef std::shared_ptr<Timed> TimedPtr;
typedef std::shared_ptr<Unit> UnitPtr;


#endif //CHECKERS_TYPEDEFS_H
