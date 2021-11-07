#include "Figura.h"
#include "Punkt.h"
#include <iostream>

using namespace std;


int main() {
  // 1.
  Punkt p1(3, 5);
  Punkt p2(-2, 1);

  cout << "Odleglosc pomiedzy punktami P1 i P2: " << p1.odlegloscOdPunktu(p2);
  cout << "\n\n";

  // 2.
  Figura f(3);
  f.wczytajWierzcholki();
  f.wypiszWierzcholki();

  return 0;
}