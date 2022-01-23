#include "Episode.h"


void Episode::print() {
  cout << "   Tytul: " << title;
  cout << "\n   Rok wydania: " << releaseYear;
  cout << "\n   Sciezka: " << path;
  cout << "\n   Wlasciciel: " << this->getOwner();
  cout << "\n   Publiczny: " << (this->isPublic() ? "true" : "false");

  cout << "\n   Dlugosc: " << MediaElement::secondsToHours(metadata.length);
  cout << "\n   Gatunek: " << metadata.genere;
  cout << "\n   Data wydania: " << metadata.releaseDate;

  cout << "\n   Nazwa serialu: " << metadata.series;
  cout << "\n   Numer odcinka: " << metadata.episodeNumber;
  cout << "\n   Numer sezonu: " << metadata.seasonNumber;

  cout << "\n   Obsada:";
  for (auto &star : metadata.cast) {
    cout << "\n      " << star.first << ": " << star.second;
  }

  cout << endl;
}

CSV Episode::generateCSV() {
  CSV csv;

  csv << title;
  csv << releaseYear;
  csv << path;
  csv << getOwner();
  csv << isPublic();

  csv << metadata.length;
  csv << metadata.genere;
  csv << metadata.releaseDate;

  csv << metadata.series;
  csv << metadata.seasonNumber;
  csv << metadata.episodeNumber;

  for (auto &star : metadata.cast) {
    csv << star.first;
    csv << star.second;
  }

  return csv;
}

void Episode::printLocation() {
  cout << "Biblioteka[" << getOwner() << "] -> Seriale -> " << metadata.series << " -> Sezon " << metadata.seasonNumber
       << " -> Epizod " << metadata.episodeNumber << " -> " << title << "(" << releaseYear << ")\n";
}