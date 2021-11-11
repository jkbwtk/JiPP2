#include "Pojazd.h"


string Pojazd::najnowszaWersjaOprogramowania = "v1.0";

Pojazd::Pojazd(int nR, string nzw, int iM, string mrk, string typ, string v)
    : numerRejestracyjny(nR), nazwa(nzw), iloscMiejsc(iM), marka(mrk), typ(typ), zaistalowanaWersjaOprogramowania(v) {
  pasazerowie = new string[iloscMiejsc];

  for (int i = 0; i < iloscMiejsc; i++)
    pasazerowie[i] = "puste";
}

Pojazd::Pojazd(const Pojazd &p) {
  numerRejestracyjny               = p.numerRejestracyjny;
  nazwa                            = p.nazwa;
  iloscMiejsc                      = p.iloscMiejsc;
  marka                            = p.marka;
  typ                              = p.typ;
  zaistalowanaWersjaOprogramowania = p.zaistalowanaWersjaOprogramowania;

  pasazerowie = new string[iloscMiejsc];

  for (int i = 0; i < iloscMiejsc; i++)
    pasazerowie[i] = p.pasazerowie[i];
}

void Pojazd::wypisz() const {
  cout << "Marka: " << marka;
  cout << "\nNazwa: " << nazwa;
  cout << "\nTyp: " << typ;
  // cout << "\nZainstalowana wersja oprogramowania: " << zaistalowanaWersjaOprogramowania;
  cout << "\nNumer rejesracyjny: " << numerRejestracyjny;
  cout << "\nIlosc miejsc: " << iloscMiejsc;
  cout << "\nPasarzerowie:";

  for (int i = 0; i < iloscMiejsc; i++) {
    cout << "\n   [" << i + 1 << "] " << pasazerowie[i];
  }

  cout << "\n";
}

void Pojazd::modyfikujPasazera(int miejsce, string wartosc) {
  if (miejsce < 1 || miejsce > iloscMiejsc)
    return;

  pasazerowie[miejsce - 1] = wartosc;
}
