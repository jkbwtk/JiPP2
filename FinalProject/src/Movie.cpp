#include "Movie.h"


void Movie::print() {
  cout << "   Tytul: " << title;
  cout << "\n   Rok wydania: " << releaseYear;
  cout << "\n   Sciezka: " << path;
  cout << "\n   Wlasciciel: " << this->getOwner();
  cout << "\n   Publiczny: " << (this->isPublic() ? "true" : "false");

  cout << "\n   Dlugosc: " << MediaElement::secondsToHours(metadata.length);
  cout << "\n   Gatunek: " << metadata.genere;
  cout << "\n   Data wydania: " << metadata.releaseDate;

  cout << "\n   Obsada:";
  for (auto &star : metadata.cast) {
    cout << "\n      " << star.first << ": " << star.second;
  }

  cout << endl;
}

CSV Movie::generateCSV() {
  CSV csv;

  csv << title;
  csv << releaseYear;
  csv << path;
  csv << getOwner();
  csv << isPublic();

  csv << metadata.length;
  csv << metadata.genere;
  csv << metadata.releaseDate;

  for (auto &star : metadata.cast) {
    csv << star.first;
    csv << star.second;
  }

  return csv;
}

void Movie::printLocation() {
  cout << "Biblioteka[" << getOwner() << "] -> Filmy -> " << title << "(" << releaseYear << ")\n";
}