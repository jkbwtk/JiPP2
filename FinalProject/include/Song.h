#ifndef JIPP2_SONG_H
#define JIPP2_SONG_H

#include "Csv.h"
#include "MediaElement.h"
#include <string>


struct SongMetadata {
  unsigned int length;
  string genere;
  string releaseDate;
  string artist;
  string album;
  unsigned int trackNumber;
};

class Song : public MediaElement {
private:
  SongMetadata metadata;

public:
  /**
   * @brief Tworzy nowy obiekt klasy Song
   *
   * @param title Tytuł utworu
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param owner Login właściciela
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi utworu
   */
  Song(string title, int releaseYear, string path, string owner, bool publicAccess, SongMetadata metadata)
      : MediaElement(title, releaseYear, path, owner, publicAccess), metadata(metadata) {}

  /**
   * @brief Wyświetla zawartość obiektu
   *
   */
  void print();

  /**
   * @brief Tworzy obiekt CSV przechowujący dane tego obiektu
   *
   * @return Obiekt CSV przechowujący dane tego obiektu
   */
  CSV generateCSV();

  /**
   * @brief Ustawia metadane obiektu
   *
   * @param newMetadata Metadane książki
   */
  void setMetadata(SongMetadata newMetadata) { metadata = newMetadata; }

  /**
   * @brief Pobiera metadane książki
   *
   * @return Metadane książki
   */
  SongMetadata getMetadata() { return metadata; }

  /**
   * @brief Wyświtla pozycję zasobu w bibliotece
   *
   */
  void printLocation();
};

#endif