#ifndef JIPP2_FIGURA_H
#define JIPP2_FIGURA_H

#include <iostream>

using namespace std;


class Figura {
protected:
  string nazwa;
  string kolor;

public:
  Figura(string nazwa, string kolor) : nazwa(nazwa), kolor(kolor) {}

  void info() const { cout << "Nazwa: " << nazwa << "\nKolor: " << kolor << "\n"; }
};

class Kwadrat : public Figura {
private:
  int a;

public:
  Kwadrat(string nazwa, string kolor, int a) : Figura(nazwa, kolor), a(a) {}

  int pole() { return a * a; }
  int obwod() { return 4 * a; }
};

class Prostokat : public Figura {
private:
  int a, b;

public:
  Prostokat(string nazwa, string kolor, int a, int b) : Figura(nazwa, kolor), a(a), b(b) {}

  int pole() { return a * b; }
  int obwod() { return (2 * a) + (2 * b); }
};

class Trapez : public Figura {
private:
  int apb, c, h;

public:
  Trapez(string nazwa, string kolor, int apb, int c, int h) : Figura(nazwa, kolor), apb(apb), c(c), h(h) {}

  int pole() { return apb + (2 * c); }
  double obwod() { return (apb * h) / 2.0; }
};

class Szesciakat : public Figura {
private:
  int a;

public:
  Szesciakat(string nazwa, string kolor, int a) : Figura(nazwa, kolor), a(a) {}

  double pole() { return (a * a) * 2.598; }
  int obwod() { return 6 * a; }
};


#endif // JIPP2_FIGURA_H
