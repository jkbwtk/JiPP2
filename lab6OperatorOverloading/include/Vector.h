#ifndef JIPP2_VECTOR_H
#define JIPP2_VECTOR_H

#include <iostream>

using namespace std;


class Vector {
private:
  double x, y;

public:
  Vector() {
    x = 0;
    y = 0;
  };

  Vector(double x, double y) : x(x), y(y) {}

  friend Vector operator*(const double &lhs, const Vector &rhs);

  friend std::ostream &operator<<(std::ostream &lhs, Vector &rhs);

  double length() { return sqrt(x * x + y * y); }

  Vector operator!() const { return {y, x}; }

  Vector operator+(const Vector &rhs) const { return {x + rhs.x, y + rhs.y}; }

  Vector operator-(const Vector &rhs) const { return {x - rhs.x, y - rhs.y}; }

  Vector operator*(const Vector &rhs) const { return {x * rhs.x, y * rhs.y}; }

  Vector operator*(const double &rhs) const { return {x * rhs, y * rhs}; }

  bool operator==(const Vector &rhs) const;

  Vector &operator+=(const Vector &rhs);

  void print() { cout << "X: " << x << "\tY: " << y << "\n"; }
};

#endif // JIPP2_VECTOR_H
