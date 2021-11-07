#include "FunkcjaKwadratowa.h"
#include "Kula.h"
#include "Prostopadloscian.h"
#include "Student.h"
#include <iostream>

using namespace std;


int main() {
  // 1.
  Prostopadloscian p;
  p.setA(5);
  p.setB(4);
  p.setH(3);

  cout << "Pole powierzchni prosopadloscianu: " << p.polePowierzchni();

  // 2.
  Kula k;
  k.setPromien(2);

  cout << "\nObjetosc kuli: " << k.objetosc();

  // 3.
  FunkcjaKwadratowa f;
  f.wczytaj();

  cout << "\nWczytana funkcja: ";
  f.wyswietl();

  // 4.
  Student s;
  s.wczytaj();

  cout << "\n Procent poprawnych odpowiedzi: " << s.procent();

  return 0;
}