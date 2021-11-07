#ifndef JIPP2_PROSTOPADLOSCIAN_H
#define JIPP2_PROSTOPADLOSCIAN_H


class Prostopadloscian {
private:
  int a;
  int b;
  int h;

public:
  void setA(int a) { this->a = a; }
  void setB(int b) { this->b = b; }
  void setH(int h) { this->h = h; }

  int polePowierzchni();
};


#endif // JIPP2_PROSTOPADLOSCIAN_H
