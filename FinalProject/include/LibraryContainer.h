#ifndef JIPP2_LIBRARYCONTAINER_H
#define JIPP2_LIBRARYCONTAINER_H

#include "Album.h"
#include "Csv.h"
#include "Ebook.h"
#include "Episode.h"
#include "Movie.h"
#include "Song.h"
#include "User.h"
#include <fstream>
#include <vector>


class LibraryContainer {
private:
  unsigned int userMediaLimit;
  unsigned int userLibraryLimit;

  vector<Movie> movies;
  vector<Episode> episodes;
  vector<Song> songs;
  vector<Ebook> ebooks;

public:
  /**
   * @brief Tworzy nowy obiekt klasy LibraryContainer
   *
   */
  LibraryContainer();

  /**
   * @brief Tworzy nowy obiekt klasy LibraryContainer
   *
   * @param userMediaLimit Limit ilości pozycji dla indywidualnego typu mediów
   * @param userLibraryLimit Limit ilości pozycji w bibliotece
   */
  LibraryContainer(unsigned int userMediaLimit, unsigned int userLibraryLimit)
      : userMediaLimit(userMediaLimit), userLibraryLimit(userLibraryLimit) {}

  /**
   * @brief Pobiera wektor przechowujący filmy
   *
   * @return Wektor przechowujący filmy
   */
  vector<Movie> *getMovies() { return &movies; }

  /**
   * @brief Pobiera wektor przechowujący epizody
   *
   * @return Wektor przechowujący epizody
   */
  vector<Episode> *getEpisodes() { return &episodes; }

  /**
   * @brief Pobiera wektor przechowujący utwory
   *
   * @return Wektor przechowujący utwory
   */
  vector<Song> *getSongs() { return &songs; }

  /**
   * @brief Pobiera wektor przechowujący ebooki
   *
   * @return wektor przechowujący ebooki
   */
  vector<Ebook> *getEbooks() { return &ebooks; }

  /**
   * @brief Ustawia limity zasobów w bibliotece
   *
   * @param mediaLimit
   * @param libraryLimit
   */
  void setLimits(unsigned int mediaLimit, unsigned int libraryLimit);

  /**
   * @brief Wyświetla zawartość biblioteki dostępną dla użytkownika
   *
   * @param user Obiekt użytkownika
   */
  void print(User *const user);

  /**
   * @brief Dodaje film do biblioteki
   *
   * @param user Użytkownik dodający film
   * @param title Tytuł filmu
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi filmu
   */
  void addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                MovieMetadata metadata);

  /**
   * @brief Dodaje epizod do biblioteki
   *
   * @param user Użytkownik dodający epizod
   * @param title Tytuł epizodu
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi epizodu
   */
  void addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                EpisodeMetadata metadata);

  /**
   * @brief Dodaje utwór do biblioteki
   *
   * @param user Użytkownik dodający utwór
   * @param title Tytuł utworu
   * @param releaseYear  Rok wydania
   * @param path Ścieżka do pliku
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi utworu
   */
  void addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess, SongMetadata metadata);

  /**
   * @brief Dodaje książkę do biblioteki
   *
   * @param user Użytkownik dodający książkę
   * @param title Tytuł książki
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param publicAccess Status publicznego dostępu
   * @param metadata Struktura z metadanymi książki
   */
  void addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                EbookMetadata metadata);

  /**
   * @brief Pobiera zasób z biblioteki
   *
   * @tparam T Klasa zasobu
   * @param user Użytkownik wykonujący
   * @param mediaContainer Wektor przechwujący zasób
   * @param title Tytuł zasobu
   * @param releaseYear Rok wydania
   * @return Obiekt zasobu
   */
  template <typename T> T getMedia(User *const user, vector<T> *mediaContainer, string title, int releaseYear);

  /**
   * @brief Wyświetla zawartość biblioteki należącą do użytkownika
   *
   * @param user Użytkownik
   */
  void printUserMedia(User *const user);

  /**
   * @brief Usuwa zasób z biblioteki
   *
   * @tparam T Klasa zasobu
   * @param user Użytkownik wykonujący
   * @param mediaContainer Wektor przechwujący zasób
   * @param title Tytuł zasobu
   * @param releaseYear Rok wydania
   */
  template <typename T> void removeMedia(User *const user, vector<T> *mediaContainer, string title, int releaseYear);

  /**
   * @brief Aktualizuje metadane zasobu
   *
   * @tparam T Klasa Zasobu
   * @tparam M Struktura metadanych
   * @param user Użytkownik wykonujący
   * @param mediaContainer Wektor przechwujący zasób
   * @param title Tytuł zasobu
   * @param releaseYear Rok wydania
   * @param metadata Nowa stuktura metadanych
   */
  template <typename T, typename M>
  void editMetadata(User *const user, vector<T> *mediaContainer, string title, int releaseYear, M metadata);

  /**
   * @brief Tworzy obiekt Album przechowujący utwory
   *
   * @param song Utwór będący częścią albumu
   * @return Album
   */
  Album getAlbum(Song song);

  /**
   * @brief Zmienia publiczną widoczność zasobu
   *
   * @tparam T Klasa Zasobu
   * @param user Użytkownik wykonujący
   * @param mediaContainer Wektor przechwujący zasób
   * @param title Tytuł zasobu
   * @param releaseYear Rok wydania
   * @param visibility Nowa widoczność zasobu
   */
  template <typename T>
  void setVisibility(User *const user, vector<T> *mediaContainer, string title, int releaseYear, bool visibility);

  /**
   * @brief Zlicza ilośc zasobów należących do użytkownika
   *
   * @tparam T Klasa Zasobu
   * @param user Użytkownik
   * @param mediaContainer Wektor przechwujący zasób
   * @return Ilość zasobów
   */
  template <typename T> unsigned int countUserMedia(User *const user, vector<T> *mediaContainer);

  /**
   * @brief Zlicza ilośc zasobów należących do użytkownika w bibliotece
   *
   * @param user Użytkownik
   * @return Ilość zasobów
   */
  unsigned int countUserLibrary(User *const user);

  /**
   * @brief Usuwa wszystkie zasoby z biblioteki
   *
   */
  void clear();

  /**
   * @brief Tworzy obiekt CSV przechowujący dane tego obiektu
   *
   * @return Obiekt CSV przechowujący dane tego obiektu
   */
  CSV generateCSV();

  /**
   * @brief Przetwarza tekst na zasoby biblioteki
   *
   * @param line Teskst
   * @param header Enumerator zasobu
   */
  void parseData(string line, MEDIA_TYPE header);

  /**
   * @brief Zapisuje dane biblioteki do pliku
   *
   */
  void saveData();

  /**
   * @brief Wczytuje dane biblioteki z pliku
   *
   */
  void readData();
};

#endif