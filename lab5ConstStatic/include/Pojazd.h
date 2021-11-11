#ifndef JIPP2_POJAZD2_H
#define JIPP2_POJAZD2_H

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

  static string najnowszaWersjaOprogramowania;
  string zaistalowanaWersjaOprogramowania;

public:
  Pojazd(int nR, string nzw, int iM, string mrk, string typ, string v);
  Pojazd(const Pojazd &p);

  ~Pojazd() { delete[] pasazerowie; }

  void wypisz() const;

  void modyfikujPasazera(int miejsce, string wartosc);

  string getNazawa() const { return nazwa; }
  int getNumberRejestracyjny() const { return numerRejestracyjny; }
  string getMarka() const { return marka; }
  string getTyp() const { return typ; }

  void setNazwa(const string n) { nazwa = n; }
  void setNumerRejestracyjny(const int n) { numerRejestracyjny = n; }

  void wypiszWersjeOprogramowania() { cout << "Wersja oprogramowania: " << zaistalowanaWersjaOprogramowania << "\n"; }
  void zaktualizujOprogramowanie() { zaistalowanaWersjaOprogramowania = najnowszaWersjaOprogramowania; }
};

#endif // JIPP2_POJAZD2_H
