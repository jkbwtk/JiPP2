#ifndef JIPP2_EPISODE_H
#define JIPP2_EPISODE_H

#include "Csv.h"
#include "MediaElement.h"
#include "Movie.h"
#include <string>


struct EpisodeMetadata : MovieMetadata {
  string series;
  unsigned int seasonNumber;
  unsigned int episodeNumber;
};

class Episode : public MediaElement {
private:
  EpisodeMetadata metadata;

public:
  /**
   * @brief Tworzy nowy obiekt klasy Episode
   *
   * @param title Tytuł epizodu
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param owner Login właściciela
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi epizodu
   */
  Episode(string title, int releaseYear, string path, string owner, bool publicAccess, EpisodeMetadata metadata)
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
   * @param newMetadata Metadane epizodu
   */
  void setMetadata(EpisodeMetadata newMetadata) { metadata = newMetadata; }

  /**
   * @brief Pobiera metadane epizodu
   *
   * @return Metadane epizodu
   */
  EpisodeMetadata getMetadata() { return metadata; }

  /**
   * @brief Wyświtla pozycję zasobu w bibliotece
   *
   */
  void printLocation();
};

#endif