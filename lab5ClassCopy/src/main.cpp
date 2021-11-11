#include "Pojazd.h"
#include <iostream>

using namespace std;


int main() {
  Pojazd p(123456789, "Gremlin X", 2, "AMC", "hatchback");
  // p.wypisz();

  p.modyfikujPasazera(1, "kierowca");
  p.modyfikujPasazera(2, "pasazer #1");
  p.wypisz();

  Pojazd p2 = p;
  p2.wypisz();

  p.setNazwa("Nazwa");
  p.setNumerRejestracyjny(0);

  cout << "\nNR: " << p.getNumberRejestracyjny() << "\nNZW: " << p.getNazawa() << "\nMRK: " << p.getMarka()
       << "\nTP:" << p.getTyp();


  return 0;
}