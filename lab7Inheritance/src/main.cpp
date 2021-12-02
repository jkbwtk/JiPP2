#include "Figura.h"
#include <iostream>

using namespace std;


int main() {
  Figura f("Test", "czerwony");
  Kwadrat k("Kwadrat", "bialy", 3);
  Prostokat p("Prostokat", "niebieski", 2, 4);
  Trapez t("Trapez", "zielony", 32, 20, 16);
  Szesciakat sz("Szesciakat", "zolty", 5);

  f.info();

  cout << "\n";
  k.info();
  cout << "Obwod: " << k.obwod() << "\nPole: " << k.pole() << "\n";

  cout << "\n";
  p.info();
  cout << "Obwod: " << p.obwod() << "\nPole: " << p.pole() << "\n";

  cout << "\n";
  t.info();
  cout << "Obwod: " << t.obwod() << "\nPole: " << t.pole() << "\n";

  cout << "\n";
  sz.info();
  cout << "Obwod: " << sz.obwod() << "\nPole: " << sz.pole() << "\n";


  return 0;
}