// Code by George Alexander Wright
// www.georgeaw.com

#include <iostream>
#include <string>

#include "Point.h"

using namespace std;

const int ROWS = 7; // change these to change board size.
const int COLS = 7; // values should be no higher than 26.

class SolitaireBoard {

 private:
  char board_matrix[ROWS][COLS];

  int invalidMove(Point source, Point destination);
  // returns 0 if the move from source to destination is valid.
  // otherwise, returns an error code.
  
  void printError(int error_code);
  // prints an error message based on the error code.

  Point strToPoint(string location);
  // converts a string such as 'A1' to a point. A1 = (0,0).
  // only works with one letter in the string.

 public:
  
  SolitaireBoard();
  // constructor
  
  ~SolitaireBoard();
  // destructor
  
  void print();
  // prints out the solitaire board in its current configuration, to the screen.
  
  bool move(string source, string destination);
  // moves a marble at source to destination if the move is valid.
  // otherwise, prints an error message to the screen.
  
  bool incomplete();
  // returns true if there are still valid moves that can be made.
  
  int countMarbles();
  // counts the nuber of marbles currently on the board.

};
