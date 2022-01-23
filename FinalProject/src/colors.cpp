#include "colors.h"

string cBlack(string str) { return FG_BLACK + str + CLEAR; }
string cRed(string str) { return FG_RED + str + CLEAR; }
string cGreen(string str) { return FG_GREEN + str + CLEAR; }
string cYellow(string str) { return FG_YELLOW + str + CLEAR; }
string cBlue(string str) { return FG_BLUE + str + CLEAR; }
string cMagenta(string str) { return FG_MAGENTA + str + CLEAR; }
string cCyan(string str) { return FG_CYAN + str + CLEAR; }
string cWhite(string str) { return FG_WHITE + str + CLEAR; }

string bgBlack(string str) { return BG_BLACK + str + CLEAR; }
string bgRed(string str) { return BG_RED + str + CLEAR; }
string bgGreen(string str) { return BG_GREEN + str + CLEAR; }
string bgYellow(string str) { return BG_YELLOW + str + CLEAR; }
string bgBlue(string str) { return BG_BLUE + str + CLEAR; }
string bgMagenta(string str) { return BG_MAGENTA + str + CLEAR; }
string bgCyan(string str) { return BG_CYAN + str + CLEAR; }
string bgWhite(string str) { return BG_WHITE + str + CLEAR; }

string bold(string str) { return BOLD + str + CLEAR; }
string italic(string str) { return ITALIC + str + CLEAR; }
string underline(string str) { return UNDERLINE + str + CLEAR; }

void fullSelfTest(string str) {
  cout << cBlack(str) << "\t";
  cout << bgBlack(str) << "\t";
  cout << bold(str) << endl;

  cout << cRed(str) << "\t";
  cout << bgRed(str) << "\t";
  cout << italic(str) << endl;

  cout << cGreen(str) << "\t";
  cout << bgGreen(str) << "\t";
  cout << underline(str) << endl;

  cout << cYellow(str) << "\t";
  cout << bgYellow(str) << "\t";
  cout << bgWhite(cCyan(bold(underline(str)))) << endl;

  cout << cBlue(str) << "\t";
  cout << bgBlue(str) << endl;

  cout << cMagenta(str) << "\t";
  cout << bgMagenta(str) << endl;

  cout << cCyan(str) << "\t";
  cout << bgCyan(str) << endl;

  cout << cWhite(str) << "\t";
  cout << bgWhite(str) << endl;
}
