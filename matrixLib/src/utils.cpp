#include "utils.h"


template int **allocateMatrix(int x, int y);
template double **allocateMatrix(int x, int y);
template <typename T> T **allocateMatrix(int x, int y) {
  T **matrix = nullptr;

  try {
    matrix = new T *[x];

    for (int i = 0; i < x; i++) {
      matrix[i] = nullptr;
      matrix[i] = new T[y];
    }
  } catch (std::bad_alloc) {
    std::cerr << "\n Brak pamieci ";
    exit(0);
  }

  return matrix;
}

template int **readMatrix(int x, int y);
template double **readMatrix(int x, int y);
template <typename T> T **readMatrix(int x, int y) {
  T **matrix = allocateMatrix<T>(x, y);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      getValue(matrix[i][j]);
    }
  }

  return matrix;
}

template int **fillMatrix(int x, int y, int value);
template double **fillMatrix(int x, int y, double value);
template <typename T> T **fillMatrix(int x, int y, T value) {
  T **matrix = allocateMatrix<T>(x, y);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      matrix[i][j] = value;
    }
  }

  return matrix;
}

template int **fillMatrixGradient(int x, int y, int value);
template double **fillMatrixGradient(int x, int y, double value);
template <typename T> T **fillMatrixGradient(int x, int y, T value) {
  T **matrix = allocateMatrix<T>(x, y);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      matrix[i][j] = value - i - j;
    }
  }

  return matrix;
}

template void printMatrix(int **a, int x, int y);
template void printMatrix(double **a, int x, int y);
template <typename T> void printMatrix(T **a, int x, int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
#ifdef _DEBUG
      cerr << a[i][j] << " ";
#else
      cout << a[i][j] << " ";
#endif
    }
    cout << endl;
  }
}

template void copyMatrix(int **a, int **b, int x, int y);
template void copyMatrix(double **a, double **b, int x, int y);
template <typename T> void copyMatrix(T **source, T **target, int x, int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      target[i][j] = source[i][j];
    }
  }
}

template void deleteMatrix(int **a, int x, int y);
template void deleteMatrix(double **a, int x, int y);
template <typename T> void deleteMatrix(T **a, int x, int y) {
  for (int i = 0; i < x; i++)
    delete[] a[i];

  delete[] a;
}

template void getValue(int &x);
template void getValue(unsigned int &x);
template void getValue(double &x);
template <typename T> void getValue(T &x) {
  cin >> x;
  if (!cin.good()) {
    cout << "Wprowadzono wartosc inna niz liczbowa!";
    exit(1);
  }
}

int getMode() {
#ifdef _DEBUG
  return 1;
#else
  int mode;

  cout << "Wpisz [0] dla trybu INT lub [1] dla trybu DOUBLE:";
  getValue(mode);

  if (mode != 0 && mode != 1) {
    cout << "Mozliwe wartosci: 0, 1!";
    exit(1);
  }

  return mode;
#endif
}

void help() {
#ifndef _DEBUG
  cout << "\nmatrixApp - instrukcja obslugi\n\n"
          "Mozliwe argumenty:\n"

          " - addMatrix: Dodaje do siebie dwie macierze\n"
          "\t Argumenty: [wiersze] [kolumny] [macierzA] [macierzB]\n"

          " - subtractMatrix: Odejmuje od siebie dwie macierze\n"
          "\t Argumenty: [wiersze] [kolumny] [macierzA] [macierzB]\n"

          " - multiplyMatrix: Mnoży przez siebie dwie macierze\n"
          "\t Argumenty: [wiersze] [kolumnyA] [kolumnyB] [macierzA] [macierzB]\n"

          " - multiplyByScalar: Mnozy macierz przez skalar\n"
          "\t Argumenty: [wiersze] [kolumny] [skalar] [macierz]\n"

          " - transpozeMatrix: Transponuje macierz\n"
          "\t Argumenty: [wiersze] [kolumny] [macierz]\n"

          " - powerMatrix: Poteguje macierz do podanego stopnia\n"
          "\t Argumenty: [wiersze] [kolumny] [potega] [macierz]\n"

          " - determinantMatrix: Oblicza wyznacznik macierzy\n"
          "\t Argumenty: [wiersze] [kolumny] [macierz]\n"

          " - matrixIsDiagonal: Sprawdza czy macierz jest diagonalna\n"
          "\t Argumenty: [wiersze] [kolumny] [macierz]\n"

          " - swap: Zamienia miejscami dwie wartosci\n"
          "\t Argumenty: [wartoscA] [wartoscB]\n"

          " - sortRow: Sortuje tablice algorytmem babelkowym\n"
          "\t Argumenty: [rozmiar] [tablica]\n"

          " - sortRowsInMatrix: Sortuje wszystkie wiersze macierzy\n"
          "\t Argumenty: [wiersze] [kolumny] [macierz]\n"

          " - help: Wypisuje ten komunikat\n"

          "\nPrzyklad wprowadzania danych dla \"transpozeMatrix\":\n"
          "3 4\n"
          "2 4 2 5\n"
          "7 3 1 6\n"
          "2 5 7 3\n"

          "\nUwagi:\n"
          " - Podawane rozmiary macierzy nie sa sprawdzane pod katem poprawnosci\n"
          " - Podanie wartosci niewlasciwego typu konczy program komunikatem o bledzie\n"
          " - Podanie blednego parametru uruchamiania wyswietla ten komunikat";
#endif
}
