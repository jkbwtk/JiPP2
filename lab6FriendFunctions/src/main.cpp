#include "Node.h"
#include <iostream>

using namespace std;


int main() {
  Node a(1, 1);
  Node b(2, 2);

  a.display();

  a.updateValue(3, 1);
  a.display();

  reverse(a);
  a.display();

  cout << "Odleglosc: " << pointsDistance(a, b) << "\n";


  return 0;
}