// Code by George Alexander Wright
// www.georgeaw.com

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Point {
  
 private:
  int x;
  int y;
  
 public:
  
  Point(int _x, int _y);
  // constructor.
  
  int row();
  // returns the row number of the point (y coordinate).

  int col();
  // returns the column number of the point (x coordinate).

};

#endif
  
