// Code by George Alexander Wright
// www.georgeaw.com

#include "Point.h"

using namespace std;

Point::Point(int _x, int _y) {
  x = _x;
  y = _y;
}

int Point::row() {
  return y;
}

int Point::col() {
  return x;
}
