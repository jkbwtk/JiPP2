#include "Vector.h"


Vector operator*(const double &lhs, const Vector &rhs) { return {lhs * rhs.x, lhs * rhs.y}; }

std::ostream &operator<<(std::ostream &lhs, Vector &rhs) { return lhs << "X: " << rhs.x << "\tY: " << rhs.y; }

Vector &Vector::operator+=(const Vector &rhs) {
  this->x = this->x + rhs.x;
  this->y = this->y + rhs.y;
  return *this;
}

bool Vector::operator==(const Vector &rhs) const {
  if (x != rhs.x || y != rhs.y)
    return false;
  else
    return true;
}