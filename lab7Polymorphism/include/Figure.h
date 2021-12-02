#ifndef JIPP2_FIGURE_H
#define JIPP2_FIGURE_H

#include <iostream>

using namespace std;


class Figure {
public:
  virtual double getArea() = 0; // Przypisujemy 0, aby nie było ciała metody
};

class Circle : public Figure {
private:
  int r;

public:
  Circle(int r) : r(r) {}

  double getArea() { return 3.1415 * (r * r); }
};

class Rectangle : public Figure {
private:
  int a, b;

public:
  Rectangle(int a, int b) : a(a), b(b) {}

  double getArea() { return a * b; }
};


#endif // JIPP2_FIGURE_H
