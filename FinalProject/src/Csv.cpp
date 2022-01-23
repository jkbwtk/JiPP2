#include "Csv.h"


void CSV::header(string name) {
  if (csv.length() != 0) {
    if (csv[csv.length() - 2] != '\n') {
      if (csv[csv.length() - 1] == '\n')
        csv += '\n';
    } else {
      csv += "\n\n";
    }
  }

  csv += "[" + name + "]\n";
}

string CSV::extractString(string &line, string::iterator &head) {
  try {
    if (head == line.end())
      throw "Bledna ilosc pol w pliku konfiguracyjnym!";

    string bufor;

    for (head; *head != ';' && head != line.end(); head++) {
      bufor += *head;
    }

    if (head != line.end())
      head++;

    return bufor;
  } catch (const char *err) {
    cerr << cRed(err) << endl;
    exit(EXIT_FAILURE);
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

ostream &operator<<(ostream &lhs, const CSV &rhs) { return lhs << rhs.csv; };