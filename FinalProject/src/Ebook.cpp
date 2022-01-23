#include "Ebook.h"


void Ebook::print() {
  cout << "   Tytul: " << title;
  cout << "\n   Rok wydania: " << releaseYear;
  cout << "\n   Sciezka: " << path;
  cout << "\n   Wlasciciel: " << this->getOwner();
  cout << "\n   Publiczny: " << (this->isPublic() ? "true" : "false");

  cout << "\n   Ilosc stron: " << metadata.numberOfPages;
  cout << "\n   Gatunek: " << metadata.genere;
  cout << "\n   Data wydania: " << metadata.releaseDate;
  cout << "\n   Autor: " << metadata.author;

  cout << endl;
}

CSV Ebook::generateCSV() {
  CSV csv;

  csv << title;
  csv << releaseYear;
  csv << path;
  csv << getOwner();
  csv << isPublic();

  csv << metadata.numberOfPages;
  csv << metadata.genere;
  csv << metadata.releaseDate;
  csv << metadata.author;

  return csv;
}

void Ebook::printLocation() {
  cout << "Biblioteka[" << getOwner() << "] -> Ebooki -> " << metadata.author << " -> "
       << " -> " << title << "\n";
}