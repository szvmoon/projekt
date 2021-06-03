#include <iostream>

#include <Game.h>
#include <Player.h>
#include <Board.h>
#include <Field.h>
#include <Basic.h>


using namespace std;

int main(){
    Basic game1;
    BoardPtr board = make_shared<Board>();
    PlayerPtr player1 =make_shared<Player>("jacek");
    PlayerPtr player2 =make_shared<Player>("krzys");
    game1.play(player1,player2, board);


    return 0;
}
