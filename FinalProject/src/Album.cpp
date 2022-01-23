#include "Album.h"

Album::Album(Song song) {
  metadata    = song.getMetadata();
  releaseYear = song.releaseYear;
}

void Album::print() {
  cout << "Album: " << metadata.album << " - Wykonawca: " << metadata.artist << endl;
  cout << "Gatunek: " << metadata.genere << ", Rok: " << releaseYear << endl;


  for (auto &track : tracks) {
    cout << "   " << track->getMetadata().trackNumber << ". " << track->title << "("
         << MediaElement::secondsToMinutes(track->getMetadata().length) << ")\n";
  }
}