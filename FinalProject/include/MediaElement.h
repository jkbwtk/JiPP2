#ifndef JIPP2_MEDIAELEMENT_H
#define JIPP2_MEDIAELEMENT_H

#include "Csv.h"
#include <string>

using namespace std;


struct MediaMetadata {
  string title;
  unsigned int releaseYear;
  string path;
  string owner;
  bool publicAccess;
};

enum MEDIA_TYPE { MOVIE, EPISODE, SONG, EBOOK };

class MediaElement {
private:
  string owner;
  bool publicAccess;

public:
  string title;
  int releaseYear;
  string path;

  /**
   * @brief Tworzy nowy obiekt klasy MediaElement
   *
   * @param title Tytuł
   * @param releaseYear Rok wydania
   * @param path Ścieżka do pliku
   * @param owner Login właściciela
   * @param publicAccess Status publicznego dostępu
   */
  MediaElement(string title, int releaseYear, string path, string owner, bool publicAccess)
      : title(title), releaseYear(releaseYear), path(path), owner(owner), publicAccess(publicAccess) {}

  /**
   * @brief Ustawoa tytuł
   *
   * @param newTitle Tytuł
   */
  void setTitle(string newTitle) { title = newTitle; }

  /**
   * @brief Ustawia rok wydania
   *
   * @param newReleaseYear Rok wydania
   */
  void setReleaseYear(int newReleaseYear) { releaseYear = newReleaseYear; }

  /**
   * @brief Ustawia właściciea
   *
   * @param user Login użytkownika
   */
  void setOwner(string user) { owner = user; }

  /**
   * @brief Ustawia publiczność zasobu
   *
   * @param status Widoczność
   */
  void setVisibility(bool status) { publicAccess = status; }

  /**
   * @brief Ustawia ścieżkę zasobu
   *
   * @param newPath Ścieżka
   */
  void setPath(string newPath) { path = newPath; }

  /**
   * @brief Pobiera właściciela zasobu
   *
   * @return Login właściciela
   */
  string getOwner() { return owner; }

  /**
   * @brief Sprawdza czy zasób jest publiczny
   *
   * @return Status widoczności zasobu
   */
  bool isPublic() { return publicAccess; }

  /**
   * @brief Konwertuje sekundy do formatu MM:SS
   *
   * @param length Sekundy
   * @return Sformatowany tekst
   */
  static string secondsToMinutes(unsigned int length);

  /**
   * @brief Konwertuje sekundy do formatu HH:MM:SS
   *
   * @param length  Sekundy
   * @return Sformatowany tekst
   */
  static string secondsToHours(unsigned int length);

  virtual void print() = 0;

  virtual CSV generateCSV() = 0;

  virtual void printLocation() = 0;
};

#endif