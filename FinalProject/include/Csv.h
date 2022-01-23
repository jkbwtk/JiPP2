#ifndef JIPP2_CSV_H
#define JIPP2_CSV_H

#include "colors.h"
#include <iostream>
#include <string>


using namespace std;


class CSV {
private:
  string csv;

public:
  void operator<<(const string &rhs) { csv += rhs + ";"; }

  void operator<<(const int &rhs) {
    char buf[256];
    sprintf_s(buf, "%d", rhs);
    csv += buf;
    csv += ";";
  }
  void operator<<(const unsigned int &rhs) {
    char buf[256];
    sprintf_s(buf, "%d", rhs);
    csv += buf;
    csv += ";";
  }
  void operator<<(const bool &rhs) {
    csv += (rhs ? "1" : "0");
    csv += ";";
  }

  void operator<<(const CSV &rhs) { csv += rhs.csv + "\n"; }

  friend ostream &operator<<(ostream &lhs, const CSV &rhs);

  /**
   * @brief Dodaje nagłówek to aktualnego dokumentu
   *
   * @param name Nazwa nagłówka
   */
  void header(string name);

  /**
   * @brief Pobiera następną wartość pola z tekstu
   *
   * @param line Linia tekstu
   * @param head Iterator tekstu
   * @return Wartość pola
   */
  static string extractString(string &line, string::iterator &head);
};

ostream &operator<<(ostream &lhs, const CSV &rhs);


#endif