#ifndef JIPP2_NODE_H
#define JIPP2_NODE_H

#include <iostream>

using namespace std;


class Node {
private:
  double x, y;

public:
  Node();
  Node(double x, double y);

  void display();

  void updateValue(double x, double y);

  friend void reverse(Node &n);

  friend double pointsDistance(Node a, Node b);
};


#endif // JIPP2_NODE_H
