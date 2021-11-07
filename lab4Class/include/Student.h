#ifndef JIPP2_STUDENT_H
#define JIPP2_STUDENT_H

#include <iostream>

using namespace std;


class Student {
public:
  string imie;
  string nazwisko;
  int numerAlbumu;
  int liczbaPytan;
  int poprawneOdpowiedzi;

  void wczytaj();
  double procent();
};


#endif // JIPP2_STUDENT_H
