#ifndef JIPP2_MOVIE_H
#define JIPP2_MOVIE_H

#include "Csv.h"
#include "MediaElement.h"
#include <string>
#include <vector>


struct MovieMetadata {
  unsigned int length;
  string genere;
  string releaseDate;
  vector<pair<string, string>> cast;
};

class Movie : public MediaElement {
private:
  MovieMetadata metadata;

public:
  /**
   * @brief Tworzy nowy obiekt klasy Movie
   *
   * @param title Tytuł filmu
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param owner Login właściciela
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi filmu
   */
  Movie(string title, int releaseYear, string path, string owner, bool publicAccess, MovieMetadata metadata)
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
  void setMetadata(MovieMetadata newMetadata) { metadata = newMetadata; }

  /**
   * @brief Pobiera metadane książki
   *
   * @return Metadane książki
   */
  MovieMetadata getMetadata() { return metadata; }

  /**
   * @brief Wyświtla pozycję zasobu w bibliotece
   *
   */
  void printLocation();
};

#endif