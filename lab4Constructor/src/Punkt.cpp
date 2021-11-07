#include "Punkt.h"


Punkt::Punkt(int x, int y) : x(x), y(y){};

double Punkt::odlegloscOdPunktu(Punkt p) {
  int odleglosc = (p.x - x) * (p.x - x);
  odleglosc += (p.y - y) * (p.y - y);

  return sqrt(odleglosc);
}