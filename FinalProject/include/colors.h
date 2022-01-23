#ifndef JIPP2_COLORS_H
#define JIPP2_COLORS_H

#include <iostream>
#include <string>

using namespace std;

#define CLEAR "\033[0m"

#define FG_BLACK "\033[30m"
#define FG_RED "\033[31m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_BLUE "\033[34m"
#define FG_MAGENTA "\033[35m"
#define FG_CYAN "\033[36m"
#define FG_WHITE "\033[37m"

#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

string cBlack(string str);
string cRed(string str);
string cGreen(string str);
string cYellow(string str);
string cBlue(string str);
string cMagenta(string str);
string cCyan(string str);
string cWhite(string str);

string bgBlack(string str);
string bgRed(string str);
string bgGreen(string str);
string bgYellow(string str);
string bgBlue(string str);
string bgMagenta(string str);
string bgCyan(string str);
string bgWhite(string str);

string bold(string str);
string italic(string str);
string underline(string str);

/**
 * @brief Wywołuje wszystkie implementowane funkcje i wypisuje na ekran;
 *
 * @param str Testowy ciąg znaków
 */
void fullSelfTest(string str = "test");

#endif // JIPP2_COLORS_H