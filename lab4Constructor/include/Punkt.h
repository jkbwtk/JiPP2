#ifndef JIPP2_PUNKT_H
#define JIPP2_PUNKT_H

#include <iostream>

using namespace std;


class Punkt {
public:
  int x;
  int y;

  Punkt() : x(0), y(0){};
  Punkt(int x, int y);

  double odlegloscOdPunktu(Punkt p);
};


#endif // JIPP2_PUNKT_H
