#ifndef JIPP2_ALBUM_H
#define JIPP2_ALBUM_H

#include "Song.h"
#include <vector>


class Album {
private:
  SongMetadata metadata;
  unsigned int releaseYear;
  vector<Song *> tracks;

public:
  /**
   * @brief Tworzy nowy obiekt klasy Album
   *
   * @param song Utwór
   */
  Album(Song song);

  /**
   * @brief Niszczy obiekt klasy Album
   *
   */
  ~Album() { cout << "Wywolano destruktor Albumu\n"; }

  /**
   * @brief Dodaje utwór do albumu
   *
   * @param song Utwor
   */
  void addTrack(Song song) { tracks.push_back(new Song(song)); }

  /**
   * @brief Pobiera wektor utworów
   *
   * @return Wektor utworow
   */
  vector<Song *> getTracks() { return tracks; }

  void print();
};

#endif