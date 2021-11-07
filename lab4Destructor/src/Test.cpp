#include "Test.h"


Test::Test() { cout << "Konstruktor nie wywolany\n"; };

Test::~Test() {
  cout << "Wywolanie destruktora\n";
  delete[] array;
}

void Test::pause() { system("pause"); }