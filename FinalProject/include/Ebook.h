#ifndef JIPP2_EBOOK_H
#define JIPP2_EBOOK_H

#include "Csv.h"
#include "MediaElement.h"
#include <string>

struct EbookMetadata {
  unsigned int numberOfPages;
  string genere;
  string releaseDate;
  string author;
};

class Ebook : public MediaElement {
private:
  EbookMetadata metadata;

public:
  /**
   * @brief Tworzy nowy obiekt klasy Ebook
   *
   * @param title Tytuł książki
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param owner Login właściciela
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi książki
   */
  Ebook(string title, int releaseYear, string path, string owner, bool publicAccess, EbookMetadata metadata)
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
  void setMetadata(EbookMetadata newMetadata) { metadata = newMetadata; }

  /**
   * @brief Pobiera metadane książki
   *
   * @return Metadane książki
   */
  EbookMetadata getMetadata() { return metadata; }

  /**
   * @brief Wyświtla pozycję zasobu w bibliotece
   *
   */
  void printLocation();
};

#endif