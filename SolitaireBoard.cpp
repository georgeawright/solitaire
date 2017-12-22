// Code by George Alexander Wright
// www.georgeaw.com

#include "SolitaireBoard.h"

using namespace std;

SolitaireBoard::SolitaireBoard() {
  int cdiv = COLS / 3;
  int rdiv = ROWS / 3;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (((i < rdiv) && (j < cdiv))
	  ||((i < rdiv) && (j >= COLS - cdiv))
	  ||((i >= ROWS - rdiv) && (j < cdiv))
	  ||((i >= ROWS - rdiv) && (j >= COLS - cdiv))) {
	board_matrix[i][j] = '|';
      }
      else if ((i == ROWS / 2) && (j == COLS / 2)) {
	board_matrix[i][j] = ' ';
      }
      else {
	board_matrix[i][j] = 'O';
      }
    }
  }
}

SolitaireBoard::~SolitaireBoard() {}

void SolitaireBoard::print() {
  char col_no = 'A';
  int row_no = ROWS + 1;
  cout << "    " << col_no;
  for (int j = 1; j < COLS; j++) {
    cout << "   " << ++col_no;
  }
  cout << "\n";  
  cout << "  +";
  for (int j = 0; j < COLS; j++) {
    cout << "---+";
  }
  cout << "\n";
  for (int i = 0; i < ROWS; i++) {
    cout << --row_no << " |";
    for (int j = 0; j < COLS; j++) {
      cout << " " << board_matrix[i][j]  << " |";
    }
    cout << "\n  +";
    for (int j = 0; j < COLS; j++) {
      cout << "---+";
    }
    cout << "\n";
  }
}

bool SolitaireBoard::move(string source, string destination) {
  Point a = strToPoint(source);
  Point b = strToPoint(destination);
  int x1 = a.col();
  int y1 = a.row();
  int x2 = b.col();
  int y2 = b.row();
  int xdiff = x2 - x1;
  int ydiff = y2 - y1;
  int invalid = invalidMove(a, b);
  if (!invalid) {
    board_matrix[y1][x1] = ' ';
    board_matrix[y2][x2] = 'O';
    if (xdiff == 2) {
      board_matrix[y1][x1 + 1] = ' ';
      return 1;
    }
    if (xdiff == -2) {
      board_matrix[y1][x1 - 1] = ' ';
      return 1;
    }
    if (ydiff == 2) {
      board_matrix[y1 + 1][x1] = ' ';
      return 1;
    }
    if (ydiff == -2) {
      board_matrix[y1 - 1][x1] = ' ';
      return 1;
    }
  }
  else {
    printError(invalid);
  }
  return 0;
}

bool SolitaireBoard::incomplete() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      Point source(j, i);
      for (int k = 0; k < ROWS; k++) {
	for (int l = 0; l < COLS; l++) {
	  Point destination(l, k);
	  if (!invalidMove(source, destination)) {
	    return 1;
	  }
	}
      }
    }
  }
  return 0;
}

int SolitaireBoard::invalidMove(Point source, Point destination) {
  int x1 = source.col();
  int y1 = source.row();
  int x2 = destination.col();
  int y2 = destination.row();
  int xdiff = x2 - x1;
  int ydiff = y2 - y1;
  if ((x1 < 0) || (y1 < 0) || (x1 >= COLS) || (y1 >= ROWS)
      || (board_matrix[y1][x1] == '|')) {
    // source not on board
    return 1;
  }
  if ((x2 < 0) || (y2 < 0) || (x2 >= COLS) || (y2 >= ROWS)
      || (board_matrix[y2][x2] == '|')) {
    // destination not on board
    return 2;
  }
  if ((xdiff == 0) && (ydiff == 0)) {
    // no move
    return 3;
  }
  if ((xdiff > 0) && (ydiff > 0)) {
    // diagonal move
    return 4;
  }
  if (!((((xdiff == 2) || (xdiff == -2)) && (ydiff == 0))
	|| ((xdiff == 0) && ((ydiff == 2) || (ydiff == -2))))) {
    // not 2 spaces in 1 direction
    return 5;
  }
  if (board_matrix[y1][x1] != 'O') {
    // no marble at source
    return 6;
  }
  if (board_matrix[y2][x2] != ' ') {
    // destination not empty
    return 7;
  }
  if (xdiff == 2) {
    if (board_matrix[y1][x1 + 1] == ' ') { // no marble
      return 8;
    }
  }
  if (xdiff == -2) {
    if (board_matrix[y1][x1 - 1] == ' ') { // in between
      return 8;
    }
  }
  if (ydiff == 2) {
    if (board_matrix[y1 + 1][x1] == ' ') { // source and
      return 8;
    }
  }
  if (ydiff == -2) {
    if (board_matrix[y1 - 1][x1] == ' ') { // destination
      return 8;
    }
  }
  return 0;
}

void SolitaireBoard::printError(int error_code) {
  switch (error_code) {
  case 1:
    cout << "The source is not a position on the board!\n";
    break;
  case 2:
    cout << "The destination is not a position on the board!\n";
    break;
  case 3:
    cout << "Staying in the same position is not a valid move!\n";
    break;
  case 4:
    cout << "Cannot move diagonally!\n";
    break;
  case 5:
    cout << "Marble must move two spaces in one direction!\n";
    break;
  case 6:
    cout << "There is no marble at the source position!\n";
    break;
  case 7:
    cout << "The destination is not empty!\n";
    break;
  case 8:
    cout << "There is no marble between the source and destination!\n";
    break;
  }
}

int SolitaireBoard::countMarbles() {
  int count = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board_matrix[j][i] == 'O') {
	count++;
      }
    }
  }
  return count;
}

Point SolitaireBoard::strToPoint(string location) {
  int x, y;
  if(isupper(location[0])) {
    x = static_cast<int>(location[0]) - 65;
  }
  else if(islower(location[0])) {
    x = static_cast<int>(location[0]) - 97;
  }
  string ystring = location.substr(1, string::npos);
  y = (stoi(ystring) - 7) * -1;
  Point point(x,y);
  return point;
}
