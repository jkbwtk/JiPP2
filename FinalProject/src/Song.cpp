#include "Song.h"


void Song::print() {
  cout << "   Tytul: " << title;
  cout << "\n   Rok wydania: " << releaseYear;
  cout << "\n   Sciezka: " << path;
  cout << "\n   Wlasciciel: " << this->getOwner();
  cout << "\n   Publiczny: " << (this->isPublic() ? "true" : "false");

  cout << "\n   Dlugosc: " << MediaElement::secondsToHours(metadata.length);
  cout << "\n   Gatunek: " << metadata.genere;
  cout << "\n   Data wydania: " << metadata.releaseDate;

  cout << "\n   Wykonawca: " << metadata.artist;
  cout << "\n   Album: " << metadata.album;
  cout << "\n   Numer utworu: " << metadata.trackNumber;

  cout << endl;
}

CSV Song::generateCSV() {
  CSV csv;

  csv << title;
  csv << releaseYear;
  csv << path;
  csv << getOwner();
  csv << isPublic();

  csv << metadata.length;
  csv << metadata.genere;
  csv << metadata.releaseDate;

  csv << metadata.artist;
  csv << metadata.album;
  csv << metadata.trackNumber;

  return csv;
}

void Song::printLocation() {
  cout << "Biblioteka[" << getOwner() << "] -> Muzyka -> " << metadata.artist << " -> " << metadata.album
       << " -> Sciezka " << metadata.trackNumber << " -> " << title << "\n";
}