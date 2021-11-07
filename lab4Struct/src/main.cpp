#include <iostream>
using namespace std;

struct samochod {
  string marka;
  string model;
  int rokProdukcji;
  string kolor;
  string naped;
};

int taSamaMrka(samochod *s, int n);
int najstarszy(samochod *s, int n);


int main() {
  int rozmiarFloty = 9;

  samochod flota[] = {{"Honda", "Civic Type R", 1997, "Bialy", "FWD"},
                      {"Honda", "S2000 CR", 2009, "Niebieski", "RWD"},
                      {"Lancia", "Stratos HF Stradale", 1974, "Czerowny", "RWD"},
                      {"Pontiac", "GTO Judge", 1969, "Pomaranczowy", "RWD"},
                      {"Chevrolet", "Corvette Stringray 427", 1967, "Bialy", "RWD"},
                      {"Chevrolet", "Impala SS 409", 1964, "Czerwony", "RWD"},
                      {"Chevrolet", "Corvette ZR-1", 1970, "Niebieski", "RWD"},
                      {"Toyota", "Celica GT-Four ST205", 1994, "Bialy", "AWD"},
                      {"Toyota", "GT86", 2013, "Pomaranczowy", "RWD"}};


  cout << "Marka\tModel \tRok \tKolor \tNaped" << endl;
  cout << "----------------------------------" << endl;

  for (int i = 0; i < rozmiarFloty; i++) {
    cout << flota[i].marka << "\t" << flota[i].model << "\t" << flota[i].rokProdukcji << "\t" << flota[i].kolor << "\t"
         << flota[i].naped << endl;
  }

  cout << "\n\nIlosc samochodow tej samej marki: " << taSamaMrka(flota, rozmiarFloty);
  cout << "\nIndeks najstarszego samochodu: " << najstarszy(flota, rozmiarFloty);

  return 0;
}

int taSamaMrka(samochod *s, int n) {
  string marka = "";
  int local    = 0;
  int maxx     = 0;
  int head     = 0;
  int i        = 0;

  while (head < n) {
    if (s[head].marka == marka) {
      head++;
    } else {
      local = 0;
      marka = s[head].marka;
      head++;

      for (i = 0; i < n; i++) {
        if (s[i].marka == marka)
          local++;
      }

      if (local > maxx)
        maxx = local;
    }
  }

  return maxx;
}

int najstarszy(samochod *s, int n) {
  int index  = 0;
  int oldest = s[0].rokProdukcji;

  for (int i = 1; i < n; i++) {
    if (oldest > s[i].rokProdukcji) {
      oldest = s[i].rokProdukcji;
      index  = i;
    }
  }

  return index;
}