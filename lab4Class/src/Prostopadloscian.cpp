#include "Prostopadloscian.h"


int Prostopadloscian::polePowierzchni() {
  int pole = 0;

  pole += 2 * a * b;
  pole += 2 * a * h;
  pole += 2 * b * h;

  return pole;
}