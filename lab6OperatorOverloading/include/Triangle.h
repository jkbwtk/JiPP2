#ifndef JIPP2_TRIANGLE_H
#define JIPP2_TRIANGLE_H

#include "Node.h"
#include <iostream>

using namespace std;


class Triangle {
private:
  string nazwa;
  Node wierzcholki[3];

public:
  Triangle() {}

  Triangle(Node a, Node b, Node c, string nazwa);

  void display();

  friend std::ostream &operator<<(std::ostream &lhs, Triangle &rhs);

  double distance(int firstPointIndex, int secondPointIndex);
};

void showTriangleData(Triangle triangle);

void showTriangleData(Triangle &triangle);

void showTriangleData(Triangle *triangle);


#endif // JIPP2_TRIANGLE_H
