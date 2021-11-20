#include "Node.h"
#include "Triangle.h"
#include "Vector.h"
#include <iostream>

using namespace std;


int main() {

  Vector v1(1, 3), v2(5, 10);
  Vector v3 = v1 + v2;
  v3.print();

  v3 = v1.operator+(v2);
  v3.print();

  cout << "Wektor przeciwny:\n";
  v3 = !v1;
  v3.print();

  cout << "Dodatwanie:\n";
  v3 = v1 + v2;
  v3.print();

  cout << "Odejmowanie:\n";
  v3 = v1 - v2;
  v3.print();

  cout << "Iloczyn skalarny:\n";
  v3 = v1 * v2;
  v3.print();

  cout << "Mnozonie przez skalar:\n";
  v3 = v1 * 3.0;
  v3.print();
  v3 = 3.0 * v1;
  v3.print();

  cout << "Porownywanie:\n";
  bool test = (v1 == v2);
  cout << "v1 == v2: " << (test ? "true" : "false") << "\n";

  cout << "\nPrzeladowanie <<:\n";
  cout << v1 << "\n";

  cout << "\n";

  Node a, b(5, 8), c(1, 16);
  Triangle triangle(a, b, c, "First Triangle");

  triangle.display();
  cout << triangle << endl;
  cout << "\nDistance between first and second point is " << triangle.distance(0, 1) << endl;


  cout << "\n";


  Triangle *t = &triangle;

  // showTriangleData(triangle);
  showTriangleData(&triangle);
  showTriangleData(t);

  return 0;
}