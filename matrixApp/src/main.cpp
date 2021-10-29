#include "matrix.h"
#include "utils.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
#ifdef _DEBUG
    cout << "TRYB DEBUGOWANIA, WYJSCIE: STDERR\n";
#endif


    if (argc < 2) {
#ifdef _DEBUG
        cerr << "Blad argumentow!";
#else
        cout << "Blad argumentow!";
#endif

        help();
        exit(1);
    }

    int mode;

    int rows, columns, columnsB, iScalar, iDeterminant, diagonal, n, i;
    double dScalar, dDeterminant;
    unsigned int power;
    int **iMatrixA, **iMatrixB, **iResult;
    double **dMatrixA, **dMatrixB, **dResult;
    int *iArray, *iResultArray;
    double *dArray, *dResultArray;

    if ("addMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);

        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "Wpisz macierz B:\n";
            dMatrixB = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji:\n";
            dResult = addMatrix(dMatrixA, dMatrixB, rows, columns);
            printMatrix(dResult, rows, columns);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "Wpisz macierz B:\n";
            iMatrixB = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji:\n";
            iResult = addMatrix(iMatrixA, iMatrixB, rows, columns);
            printMatrix(iResult, rows, columns);
        }
    } else if ("subtractMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "Wpisz macierz B:\n";
            dMatrixB = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji:\n";
            dResult = subtractMatrix(dMatrixA, dMatrixB, rows, columns);
            printMatrix(dResult, rows, columns);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "Wpisz macierz B:\n";
            iMatrixB = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji:\n";
            iResult = subtractMatrix(iMatrixA, iMatrixB, rows, columns);
            printMatrix(iResult, rows, columns);
        }
    } else if ("multiplyMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn macierzy A: ";
        getValue(columns);
        cout << "Podaj liczbe kolumn macierzy B: ";
        getValue(columnsB);

        cout << rows << " " << columns << " " << columnsB << "\n";

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "Wpisz macierz B:\n";
            dMatrixB = readMatrix<double>(columns, columnsB);

            cout << "\nWynik operacji:\n";
            dResult = multiplyMatrix(dMatrixA, dMatrixB, rows, columns, columnsB);
            printMatrix(dResult, rows, columnsB);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "Wpisz macierz B:\n";
            iMatrixB = readMatrix<int>(columns, columnsB);

            cout << "\nWynik operacji:\n";
            iResult = multiplyMatrix(iMatrixA, iMatrixB, rows, columns, columnsB);
            printMatrix(iResult, rows, columnsB);
        }
    } else if ("multiplyByScalar" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Podaj wartość skalara: ";
            getValue(dScalar);

            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji:\n";
            dResult = multiplyByScalar(dMatrixA, rows, columns, dScalar);
            printMatrix(dResult, rows, columns);
        } else {
            cout << "Podaj wartość skalara: ";
            getValue(iScalar);

            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji:\n";
            iResult = multiplyByScalar(iMatrixA, rows, columns, iScalar);
            printMatrix(iResult, rows, columns);
        }

    } else if ("transpozeMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji:\n";
            dResult = transpozeMatrix(dMatrixA, rows, columns);
            printMatrix(dResult, columns, rows);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji:\n";
            iResult = transpozeMatrix(iMatrixA, rows, columns);
            printMatrix(iResult, columns, rows);
        }
    } else if ("powerMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);
        cout << "Podaj moc potegi: ";
        getValue(power);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji:\n";
            dResult = powerMatrix(dMatrixA, power, rows, columns);
            printMatrix(dResult, rows, columns);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji:\n";
            iResult = powerMatrix(iMatrixA, power, rows, columns);
            printMatrix(iResult, rows, columns);
        }
    } else if ("determinantMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            dDeterminant = determinantMatrix(dMatrixA, rows, columns);
            cout << "\nWynik operacji: ";
#ifdef _DEBUG
            cerr << dDeterminant;
#else
            cout << dDeterminant;
#endif
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            iDeterminant = determinantMatrix(iMatrixA, rows, columns);
            cout << "\nWynik operacji: ";
#ifdef _DEBUG
            cerr << iDeterminant;
#else
            cout << iDeterminant;
#endif
        }
    } else if ("matrixIsDiagonal" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji: ";
            diagonal = matrixIsDiagonal(dMatrixA, rows, columns);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji: ";
            diagonal = matrixIsDiagonal(iMatrixA, rows, columns);
        }

#ifdef _DEBUG
        cerr << diagonal ? "true" : "false";
#else
        cout << diagonal ? "true" : "false";
#endif
    } else if ("swap" == string(argv[1])) {
        mode = getMode();

        if (mode) {
            cout << "Podaj wartosc A: ";
            getValue(dScalar);
            cout << "Podaj wartosc B: ";
            getValue(dDeterminant);

            cout << "\nWynik operacji: ";
            swap(dScalar, dDeterminant);
#ifdef _DEBUG
            cerr << dScalar << ", " << dDeterminant;
#else
            cout << dScalar << ", " << dDeterminant;
#endif
        } else {
            cout << "Podaj wartosc A: ";
            getValue(iScalar);
            cout << "Podaj wartosc B: ";
            getValue(iDeterminant);

            cout << "\nWynik operacji: ";
            swap(iScalar, iDeterminant);
#ifdef _DEBUG
            cerr << iScalar << ", " << iDeterminant;
#else
            cout << iScalar << ", " << iDeterminant;
#endif
        }

    } else if ("sortRow" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj rozmiar tablicy: ";
        getValue(n);

        if (mode) {
            dArray = new double[n];

            cout << "Wpisz tablice:\n";
            for (i = 0; i < n; i++)
                getValue(dArray[i]);

            cout << "\nWynik operacji:\n";
            dResultArray = sortRow(dArray, n);

            for (i = 0; i < n; i++) {
#ifdef _DEBUG
                cerr << dResultArray[i] << " ";
#else
                cout << dResultArray[i] << " ";
#endif
            }
        } else {
            iArray = new int[n];

            cout << "Wpisz tablice:\n";
            for (i = 0; i < n; i++)
                getValue(iArray[i]);

            cout << "\nWynik operacji:\n";
            iResultArray = sortRow(iArray, n);

            for (i = 0; i < n; i++) {
#ifdef _DEBUG
                cerr << iResultArray[i] << " ";
#else
                cout << iResultArray[i] << " ";
#endif
            }
        }

    } else if ("sortRowsInMatrix" == string(argv[1])) {
        mode = getMode();

        cout << "Podaj liczbe wieszy: ";
        getValue(rows);
        cout << "Podaj liczbe kolumn: ";
        getValue(columns);

        if (mode) {
            cout << "Wpisz macierz A:\n";
            dMatrixA = readMatrix<double>(rows, columns);

            cout << "\nWynik operacji:\n";
            dResult = sortRowsInMatrix(dMatrixA, rows, columns);
            printMatrix(dResult, rows, columns);
        } else {
            cout << "Wpisz macierz A:\n";
            iMatrixA = readMatrix<int>(rows, columns);

            cout << "\nWynik operacji:\n";
            iResult = sortRowsInMatrix(iMatrixA, rows, columns);
            printMatrix(iResult, rows, columns);
        }
    } else if ("help" == string(argv[1])) {
        help();
    } else {
#ifdef _DEBUG
        cerr << "Nieprawidlowy argument!";
#else
        cout << "Nieprawidlowy argument!";
#endif

        help();
    }


    return 0;
}
