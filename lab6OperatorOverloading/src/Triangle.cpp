#include "Triangle.h"


Triangle::Triangle(Node a, Node b, Node c, string nazwa) : nazwa(nazwa) {
  wierzcholki[0] = a;
  wierzcholki[1] = b;
  wierzcholki[2] = c;
}

std::ostream &operator<<(std::ostream &lhs, Triangle &rhs) {
  return lhs << "Nazwa: " << rhs.nazwa << ", Wierzcholek#1: " << rhs.wierzcholki[0]
             << ", Wierzcholek#2: " << rhs.wierzcholki[1] << ", Wierzcholek#3: " << rhs.wierzcholki[2];
}

void Triangle::display() {
  cout << "Nazwa: " << nazwa;
  cout << "\nWierzholek#1: ";
  wierzcholki[0].display();

  cout << "Wierzholek#2: ";
  wierzcholki[1].display();

  cout << "Wierzholek#3: ";
  wierzcholki[2].display();
}

double Triangle::distance(int firstPointIndex, int secondPointIndex) {
  if (firstPointIndex > 2 || firstPointIndex < 0)
    firstPointIndex = 0;
  if (secondPointIndex > 2 || secondPointIndex < 0)
    secondPointIndex = 1;

  return pointsDistance(wierzcholki[firstPointIndex], wierzcholki[secondPointIndex]);
}

void showTriangleData(Triangle triangle) { triangle.display(); }

void showTriangleData(Triangle &triangle) { triangle.display(); }

void showTriangleData(Triangle *triangle) { triangle->display(); }
