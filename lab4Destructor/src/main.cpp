#include "Test.h"
#include <iostream>

using namespace std;


int main() {
  Test *t;
  t = new Test;

  t->array = new int[1024];
  t->pause();
  delete t;

  system("pause");

  return 0;
}