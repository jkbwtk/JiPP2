#include "matrix.h"


int **addMatrix(int **matrixA, int **matrixB, int rows, int columns) {
  int **matrix = allocateMatrix<int>(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }

  return matrix;
}

double **addMatrix(double **matrixA, double **matrixB, int rows, int columns) {
  double **matrix = allocateMatrix<double>(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }

  return matrix;
}

int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns) {
  int **matrix = allocateMatrix<int>(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = matrixA[i][j] - matrixB[i][j];
    }
  }

  return matrix;
}

double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns) {
  double **matrix = allocateMatrix<double>(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = matrixA[i][j] - matrixB[i][j];
    }
  }

  return matrix;
}

int **multiplyMatrix(int **matrixA, int **matrixB, int rows, int columnsA, int columnsB) {
  int **matrix = allocateMatrix<int>(rows, columnsB);
  int sum      = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columnsB; j++) {
      sum = 0;
      for (int k = 0; k < columnsA; k++) {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      matrix[i][j] = sum;
    }
  }

  return matrix;
}

double **multiplyMatrix(double **matrixA, double **matrixB, int rows, int columnsA, int columnsB) {
  double **matrix = allocateMatrix<double>(rows, columnsB);
  double sum      = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columnsB; j++) {
      sum = 0;
      for (int k = 0; k < columnsA; k++) {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      matrix[i][j] = sum;
    }
  }

  return matrix;
}

int **multiplyByScalar(int **matrixA, int rows, int columns, int scalar) {
  int **matrix = allocateMatrix<int>(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = matrixA[i][j] * scalar;
    }
  }

  return matrix;
}

double **multiplyByScalar(double **matrixA, int rows, int columns, double scalar) {
  double **matrix = allocateMatrix<double>(rows, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = matrixA[i][j] * scalar;
    }
  }

  return matrix;
}

int **transpozeMatrix(int **matrixA, int rows, int columns) {
  int **matrix = allocateMatrix<int>(columns, rows);

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      matrix[i][j] = matrixA[j][i];
    }
  }

  return matrix;
}

double **transpozeMatrix(double **matrixA, int rows, int columns) {
  double **matrix = allocateMatrix<double>(columns, rows);

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      matrix[i][j] = matrixA[j][i];
    }
  }

  return matrix;
}

int **powerMatrix(int **matrixA, unsigned int power, int rows, int columns) {
  if (power == 1)
    return matrixA;

  int **matrix = allocateMatrix<int>(rows, columns);

  if (power == 0) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) {
        if (i == j)
          matrix[i][j] = 1;
        else
          matrix[i][j] = 0;
      }

    return matrix;
  }


  int **tmp = allocateMatrix<int>(rows, columns);
  int sum   = 0;

  copyMatrix(matrixA, matrix, rows, columns);

  for (int n = 1; n < power; n++) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        sum = 0;
        for (int k = 0; k < columns; k++) {
          sum += matrixA[i][k] * matrix[k][j];
        }
        tmp[i][j] = sum;
      }
    }
    copyMatrix(tmp, matrix, rows, columns);
  }

  deleteMatrix(tmp, rows, columns);
  return matrix;
}

double **powerMatrix(double **matrixA, unsigned int power, int rows, int columns) {
  if (power == 1)
    return matrixA;

  double **matrix = allocateMatrix<double>(rows, columns);

  if (power == 0) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) {
        if (i == j)
          matrix[i][j] = 1.0;
        else
          matrix[i][j] = 0;
      }

    return matrix;
  }


  double **tmp = allocateMatrix<double>(rows, columns);
  double sum   = 0;

  copyMatrix<double>(matrixA, matrix, rows, columns);

  for (int n = 1; n < power; n++) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        sum = 0;
        for (int k = 0; k < columns; k++) {
          sum += matrixA[i][k] * matrix[k][j];
        }
        tmp[i][j] = sum;
      }
    }
    copyMatrix(tmp, matrix, rows, columns);
  }

  deleteMatrix(tmp, rows, columns);
  return matrix;
}

int determinantMatrix(int **matrixA, int rows, int columns) {
  int **submatrix = allocateMatrix<int>(rows, rows);
  int determinant = 0;

  switch (rows) {
  case 1:
    determinant = matrixA[0][0];
    break;
  case 2:
    determinant = (matrixA[0][0] * matrixA[1][1]) - (matrixA[1][0] * matrixA[0][1]);
    break;
  default:
    for (int n = 0; n < rows; n++) {
      int xx = 0;
      for (int i = 1; i < rows; i++) {
        int yy = 0;
        for (int j = 0; j < rows; j++) {
          if (j == n)
            continue;
          submatrix[xx][yy] = matrixA[i][j];
          yy++;
        }
        xx++;
      }
      determinant += matrixA[0][n] * (n % 2 ? -1 : 1) * determinantMatrix(submatrix, rows - 1, rows);
    }
    break;
  }


  return determinant;
}

double determinantMatrix(double **matrixA, int rows, int columns) {
  double **submatrix = allocateMatrix<double>(rows, rows);
  double determinant = 0;

  switch (rows) {
  case 1:
    determinant = matrixA[0][0];
    break;
  case 2:
    determinant = (matrixA[0][0] * matrixA[1][1]) - (matrixA[1][0] * matrixA[0][1]);
    break;
  default:
    for (int n = 0; n < rows; n++) {
      int xx = 0;
      for (int i = 1; i < rows; i++) {
        int yy = 0;
        for (int j = 0; j < rows; j++) {
          if (j == n)
            continue;
          submatrix[xx][yy] = matrixA[i][j];
          yy++;
        }
        xx++;
      }
      determinant += matrixA[0][n] * (n % 2 ? -1 : 1) * determinantMatrix(submatrix, rows - 1, rows);
    }
    break;
  }


  return determinant;
}

bool matrixIsDiagonal(int **matrixA, int rows, int columns) {

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (i != j && matrixA[i][j] != 0)
        return false;
    }
  }

  return true;
}

bool matrixIsDiagonal(double **matrixA, int rows, int columns) {

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (i != j && matrixA[i][j] != 0)
        return false;
    }
  }

  return true;
}

void swap(int &a, int &b) {
  int tmp = a;

  a = b;
  b = tmp;
}

void swap(double &a, double &b) {
  double tmp = a;

  a = b;
  b = tmp;
}

int *sortRow(int array[], unsigned int n) {
  int *cpy = new int[n];
  int i, head;

  for (i = 0; i < n; i++)
    cpy[i] = array[i];

  for (i = 0; i < n - 1; i++)
    for (head = n - 2; head >= i; head--)
      if (cpy[head] > cpy[head + 1])
        swap(cpy[head], cpy[head + 1]);


  return cpy;
}

double *sortRow(double array[], unsigned int n) {
  double *cpy = new double[n];
  int i, head;

  for (i = 0; i < n; i++)
    cpy[i] = array[i];

  for (i = 0; i < n - 1; i++)
    for (head = n - 2; head >= i; head--)
      if (cpy[head] > cpy[head + 1])
        swap(cpy[head], cpy[head + 1]);


  return cpy;
}

int **sortRowsInMatrix(int **matrixA, int rows, int columns) {
  int **matrix = new int *[rows];

  for (int i = 0; i < rows; i++)
    matrix[i] = sortRow(matrixA[i], columns);


  return matrix;
}

double **sortRowsInMatrix(double **matrixA, int rows, int columns) {
  double **matrix = new double *[rows];

  for (int i = 0; i < rows; i++)
    matrix[i] = sortRow(matrixA[i], columns);


  return matrix;
}
