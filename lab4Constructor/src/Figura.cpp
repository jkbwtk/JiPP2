#include "Figura.h"


Figura::Figura(int n) : n(n) { wierzcholki = new Punkt[n]; };

void Figura::wczytajWierzcholki() {
  for (int i = 0; i < n; i++) {
    cout << "Wierzcholek#" << i + 1 << " [x, y]: ";
    cin >> wierzcholki[i].x;
    cin >> wierzcholki[i].y;
    cout << "\n";
  }
}

void Figura::wypiszWierzcholki() {
  for (int i = 0; i < n; i++) {
    cout << "Wierzcholek#" << i + 1 << " [" << wierzcholki[i].x << ", " << wierzcholki[i].y << "]";
    cout << "\n";
  }
}