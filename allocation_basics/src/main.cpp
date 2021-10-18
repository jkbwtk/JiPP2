#include <iostream>

using namespace std;

int main() {
    int liczba = 12345;         //zmienna liczbowa
    int *wsk = &liczba;         //przypisanie wskaźnikowi adresu zmiennej liczba

    cout << *wsk << endl;        //wyświetlenie wyłuskanej wartości wskaźnika (12345)
    cout << wsk << endl;         //wyświetlenie adresu zmiennej liczba
    cout << &wsk << endl;        //wyświetlenie adresu wskaźnika
    cout << &liczba << endl;    //wyświetlenie adresu zmiennej liczba
    
    return 0;
}