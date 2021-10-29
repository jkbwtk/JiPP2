#ifndef JIPP2_UTILS_H
#define JIPP2_UTILS_H

#include <iostream>

using namespace std;


template <typename T> T **allocateMatrix(int x, int y);

template <typename T> T **readMatrix(int x, int y);

template <typename T> T **fillMatrix(int x, int y, T value);

template <typename T> T **fillMatrixGradient(int x, int y, T value);

template <typename T> void printMatrix(T **a, int x, int y);

template <typename T> void copyMatrix(T **a, T **b, int x, int y);

template <typename T> void deleteMatrix(T **a, int x, int y);

template <typename T> void getValue(T &x);

int getMode();

void help();

#endif // JIPP2_UTILS_H
