#ifndef JIPP2_FIGURA_H
#define JIPP2_FIGURA_H

#include "Punkt.h"
#include <iostream>

using namespace std;


class Figura {
public:
  int n;
  Punkt *wierzcholki;

  Figura(int n);

  void wczytajWierzcholki();

  void wypiszWierzcholki();
};


#endif // JIPP2_FIGURA_H
