#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Brak argumentów!" << endl;
        help();
        return 1;
    }

    int a, b, c;

    if (strcmp("help", argv[1]) == 0) help();
    else if (strcmp("add", argv[1]) == 0) {
        if (argc < 4) {
            cout << "Błęda ilość argumentów!" << " Oczekiwano: 3, otrzymano " << argc - 1 << endl;
            help();
            return 2;
        }

        sscanf_s(argv[2], "%d", &a);
        sscanf_s(argv[3], "%d", &b);

        add(a, b);
    } else if (strcmp("subtract", argv[1]) == 0) {
        if (argc < 4) {
            cout << "Błęda ilość argumentów!" << " Oczekiwano: 3, otrzymano " << argc - 1 << endl;
            help();
            return 3;
        }

        sscanf_s(argv[2], "%d", &a);
        sscanf_s(argv[3], "%d", &b);

        subtract(a, b);
    } else if (strcmp("volume", argv[1]) == 0) {
        if (argc < 5) {
            cout << "Błęda ilość argumentów!" << " Oczekiwano: 4, otrzymano " << argc - 1 << endl;
            help();
            return 4;
        }

        sscanf_s(argv[2], "%d", &a);
        sscanf_s(argv[3], "%d", &b);
        sscanf_s(argv[4], "%d", &c);

        volume(a, b, c);
    } else {
        cout << "Nieznany argument!" << endl;
        help();

        return 5;
    }


    return 0;
}
