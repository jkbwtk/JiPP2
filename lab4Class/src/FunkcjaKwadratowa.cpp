#include "FunkcjaKwadratowa.h"


void FunkcjaKwadratowa::wczytaj() {
  cout << "\n\nPodaj wpolczynniki a, b i c: ";

  cin >> a;
  cin >> b;
  cin >> c;
}

void FunkcjaKwadratowa::wyswietl() { cout << "f(x) = " << a << " x^2 + " << b << " x + " << c; }