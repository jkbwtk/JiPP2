#include "calc.h"


void add(int a, int b) {
    cout << "add: " << a + b;
}

void subtract(int a, int b) {
    cout << "subtract: " << a - b;
}

void volume(int a, int b, int c) {
    cout << "volume " << (a * 0.5 * b) * c;
}

void help() {
    string help = "Simple calculator\n"
                  "simpleCalc [nazwa działania]\n"
                  "\n"
                  "Działania:\n"
                  "add [a] [b]\n"
                  "    Dodawanie dwóch liczb ([a] i [b]) całkowitych. \n"
                  "subtract [a] [b]\n"
                  "    Odejmowanie dwóch liczb ([a] i [b]) całkowitych\n"
                  "volume [suma długości podstaw] [wysokość trapezu] [wysokość graniastosłupa]\n"
                  "    Oblicza objętość graniastosłupa prostego o podstawie trapezu\n"
                  "help\n"
                  "    Wyświetla ten komunikat";

    cout << help;
}