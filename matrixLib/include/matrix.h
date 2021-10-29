#ifndef JIPP2_MATRIX_H
#define JIPP2_MATRIX_H

#include "utils.h"
#include <iostream>

using namespace std;


/**
 * @brief Dodaje do siebie dwie macierze
 *
 * @param matrixA Macierz A
 * @param matrixB Macierz B
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
int **addMatrix(int **matrixA, int **matrixB, int rows, int columns);
/**
 * @brief Dodaje do siebie dwie macierze
 *
 * @param matrixA Macierz A
 * @param matrixB Macierz B
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
double **addMatrix(double **matrixA, double **matrixB, int rows, int columns);


/**
 * @brief Odejmuje od siebie dwie macierze
 *
 * @param matrixA Macierz A
 * @param matrixB Macierz B
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns);
/**
 * @brief Odejmuje od siebie dwie macierze
 *
 * @param matrixA Macierz A
 * @param matrixB Macierz B
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns);

/**
 * @brief Mnoży przez siebie dwie macierze
 *
 * @param matrixA Macierz A
 * @param matrixB Macierz B
 * @param rows Ilość wierszy
 * @param columnsA Ilość kolumn pierwszej macierzy
 * @param columnsB Ilość kolumn drugiej macierzy
 * @return Nowa macierz wynikowa
 */
int **multiplyMatrix(int **matrixA, int **matrixB, int rows, int columnsA, int columnsB);
/**
 * @brief Mnoży przez siebie dwie macierze
 *
 * @param matrixA Macierz A
 * @param matrixB Macierz B
 * @param rows Ilość wierszy
 * @param columnsA Ilość kolumn pierwszej macierzy
 * @param columnsB Ilość kolumn drugiej macierzy
 * @return Nowa macierz wynikowa
 */
double **multiplyMatrix(double **matrixA, double **matrixB, int rows, int columnsA, int columnsB);


/**
 * @brief Mnoży macierz przez skalar
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @param scalar Skalar
 * @return Nowa macierz wynikowa
 */
int **multiplyByScalar(int **matrixA, int rows, int columns, int scalar);
/**
 * @brief Mnoży macierz przez skalar
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @param scalar Skalar
 * @return Nowa macierz wynikowa
 */
double **multiplyByScalar(double **matrixA, int rows, int columns, double scalar);

/**
 * @brief Transponuje macierz
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
int **transpozeMatrix(int **matrixA, int rows, int columns);
/**
 * @brief Transponuje macierz
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
double **transpozeMatrix(double **matrixA, int rows, int columns);

/**
 * @brief Potęguje macierz do podanego stopnia
 *
 * @param matrixA Macierz A
 * @param power Stopień potęgi
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
int **powerMatrix(int **matrixA, unsigned int power, int rows, int columns);
/**
 * @brief Potęguje macierz do podanego stopnia
 *
 * @param matrixA Macierz A
 * @param power Stopień potęgi
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Nowa macierz wynikowa
 */
double **powerMatrix(double **matrixA, unsigned int power, int rows, int columns);

/**
 * @brief Oblicza wyznacznik macierzy
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Wartość wyznacznika
 */
int determinantMatrix(int **matrixA, int rows, int columns);
/**
 * @brief Oblicza wyznacznik macierzy
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Wartość wyznacznika
 */
double determinantMatrix(double **matrixA, int rows, int columns);

/**
 * @brief Sprawdza czy macierz jest diagonalna
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return true jeżeli macierz jest diagonalna
 */
bool matrixIsDiagonal(int **matrixA, int rows, int columns);
/**
 * @brief Sprawdza czy macierz jest diagonalna
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return true jeżeli macierz jest diagonalna
 */
bool matrixIsDiagonal(double **matrixA, int rows, int columns);

/**
 * @brief Zamienia miejscami dwie wartości
 *
 * @param matrixA Liczba A
 * @param matrixB Liczba B
 */
void swap(int &matrixA, int &matrixB);
/**
 * @brief Zamienia miejscami dwie wartości
 *
 * @param matrixA Liczba A
 * @param matrixB Liczba B
 */
void swap(double &matrixA, double &matrixB);

/**
 * @brief Sortuje tablicę algorytmem bąbelkowym
 *
 * @param array Tablica
 * @param n Rozmiar tablicy
 * @return Posortowana tablica
 */
int *sortRow(int array[], unsigned int n);
/**
 * @brief Sortuje tablicę algorytmem bąbelkowym
 *
 * @param array Tablica
 * @param n Rozmiar tablicy
 * @return Posortowana tablica
 */
double *sortRow(double array[], unsigned int n);

/**
 * @brief Sortuje wszystkie wiersze macierzy
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Posortowana macierz
 */
int **sortRowsInMatrix(int **matrixA, int rows, int columns);
/**
 * @brief Sortuje wszystkie wiersze macierzy
 *
 * @param matrixA Macierz A
 * @param rows Ilość wierszy
 * @param columns Ilość kolumn
 * @return Posortowana macierz
 */
double **sortRowsInMatrix(double **matrixA, int rows, int columns);

#endif // JIPP2_MATRIX_H
