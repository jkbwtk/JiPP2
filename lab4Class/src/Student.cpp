#include "Student.h"


void Student::wczytaj() {
  cout << "\n\nPodaj dane studenta imie, nazwisko, numer albumu, liczba opdowiedzi i poprawne odpowiedzi: ";

  cin >> imie;
  cin >> nazwisko;
  cin >> numerAlbumu;
  cin >> liczbaPytan;
  cin >> poprawneOdpowiedzi;
}

double Student::procent() { return 100 * static_cast<double>(poprawneOdpowiedzi) / liczbaPytan; }