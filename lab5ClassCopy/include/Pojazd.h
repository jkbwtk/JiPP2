#ifndef JIPP2_POJAZD_H
#define JIPP2_POJAZD_H

#include <iostream>
using namespace std;

class Pojazd {
private:
  int numerRejestracyjny;
  string nazwa;
  int iloscMiejsc;

  string *pasazerowie;

  string marka;
  string typ;

public:
  Pojazd(int nR, string nzw, int iM, string mrk, string typ);
  Pojazd(Pojazd &p);

  ~Pojazd() { delete[] pasazerowie; }

  void wypisz();

  void modyfikujPasazera(int miejsce, string wartosc);

  string getNazawa() { return nazwa; }
  int getNumberRejestracyjny() { return numerRejestracyjny; }
  string getMarka() { return marka; }
  string getTyp() { return typ; }

  void setNazwa(string n) { nazwa = n; }
  void setNumerRejestracyjny(int n) { numerRejestracyjny = n; }
};


#endif // JIPP2_POJAZD_H
