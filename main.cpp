// Code by George Alexander Wright
// www.georgeaw.com

#include "SolitaireBoard.h"
#include <iostream>
using namespace std;

int main() {
  SolitaireBoard board;
  board.print();
  
  cout << "Enter a move by entering the position of a marble 'O' followed by the position you wish to move it to (e.g. 'E7 E5').\n\nA marble can only move to an empty position and must do so by jumping over another marble. When a marble has been jumped over, it is removed. Try and remove as many marbles as possible.\n\n";

  int move = 1;
  string source, destination;
  while (board.incomplete()) {
    cout << "move " << move << ": ";
    cin >> source >> destination;
    board.move(source, destination);
    board.print();
    cout << endl;
    move++;
  }

  cout << "You have finished with "
       << board.countMarbles() << " marbles left!\n";

  return 0;
}
