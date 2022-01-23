#include "LibraryContainer.h"


LibraryContainer::LibraryContainer() {
  userMediaLimit   = 0;
  userLibraryLimit = 0;
}

void LibraryContainer::setLimits(unsigned int mediaLimit, unsigned int libraryLimit) {
  userMediaLimit   = mediaLimit;
  userLibraryLimit = libraryLimit;
}

void LibraryContainer::print(User *const user) {
  cout << BG_CYAN BOLD << "Ilosc multimediow: " << movies.size() + episodes.size() + songs.size() + ebooks.size()
       << CLEAR << endl;

  cout << FG_CYAN BOLD << "Ilosc filmow: " << movies.size() << CLEAR << endl;
  for (auto &movie : movies) {
    if (!movie.isPublic())
      if (!user->isAdmin() && user->getUsername() != movie.getOwner())
        continue;

    movie.print();
    cout << endl;
  }

  cout << FG_CYAN BOLD << "Ilosc epizodow: " << episodes.size() << CLEAR << endl;
  for (auto &episode : episodes) {
    if (!episode.isPublic())
      if (!user->isAdmin() && user->getUsername() != episode.getOwner())
        continue;

    episode.print();
    cout << endl;
  }

  cout << FG_CYAN BOLD << "Ilosc piosenek: " << songs.size() << CLEAR << endl;
  for (auto &song : songs) {
    if (!song.isPublic())
      if (!user->isAdmin() && user->getUsername() != song.getOwner())
        continue;

    song.print();
    cout << endl;
  }

  cout << FG_CYAN BOLD << "Ilosc ebookow: " << ebooks.size() << CLEAR << endl;
  for (auto &ebook : ebooks) {
    if (!ebook.isPublic())
      if (!user->isAdmin() && user->getUsername() != ebook.getOwner())
        continue;

    ebook.print();
    cout << endl;
  }
}

void LibraryContainer::addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                                MovieMetadata metadata) {
  try {
    for (auto &movie : movies) {
      if (movie.title == title && movie.releaseYear == releaseYear)
        throw "Film znajduje sie juz w bibliotece!";
    }

    if (!user->isAdmin())
      if (countUserLibrary(user) >= userLibraryLimit || countUserMedia(user, getMovies()) >= userMediaLimit)
        throw "Przekroczono dopuszczalny limit elementow w bibliotece!";

    movies.emplace_back(title, releaseYear, path, user->getUsername(), publicAccess, metadata);
    cout << "Dodano film [" << title << "(" << releaseYear << ")]\n";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void LibraryContainer::addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                                EpisodeMetadata metadata) {
  try {
    for (auto &episode : episodes) {
      if (episode.title == title && episode.releaseYear == releaseYear)
        throw "Epizod znajduje sie juz w bibliotece!";
    }

    if (!user->isAdmin())
      if (countUserLibrary(user) >= userLibraryLimit || countUserMedia(user, getEpisodes()) >= userMediaLimit)
        throw "Przekroczono dopuszczalny limit elementow w bibliotece!";

    episodes.emplace_back(title, releaseYear, path, user->getUsername(), publicAccess, metadata);
    cout << "Dodano epizod [" << title << "(" << releaseYear << ")]\n";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void LibraryContainer::addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                                SongMetadata metadata) {
  try {
    for (auto &song : songs) {
      if (song.title == title && song.releaseYear == releaseYear)
        throw "Utwor znajduje sie juz w bibliotece!";
    }

    if (!user->isAdmin())
      if (countUserLibrary(user) >= userLibraryLimit || countUserMedia(user, getSongs()) >= userMediaLimit)
        throw "Przekroczono dopuszczalny limit elementow w bibliotece!";

    songs.emplace_back(title, releaseYear, path, user->getUsername(), publicAccess, metadata);
    cout << "Dodano utwor [" << title << "(" << releaseYear << ")]\n";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void LibraryContainer::addMedia(User *const user, string title, int releaseYear, string path, bool publicAccess,
                                EbookMetadata metadata) {
  try {
    for (auto &ebook : ebooks) {
      if (ebook.title == title && ebook.releaseYear == releaseYear)
        throw "Ebook znajduje sie juz w bibliotece!";
    }

    if (!user->isAdmin())
      if (countUserLibrary(user) >= userLibraryLimit || countUserMedia(user, getEbooks()) >= userMediaLimit)
        throw "Przekroczono dopuszczalny limit elementow w bibliotece!";

    ebooks.emplace_back(title, releaseYear, path, user->getUsername(), publicAccess, metadata);
    cout << "Dodano ebook [" << title << "(" << releaseYear << ")]\n";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

template Movie LibraryContainer::getMedia(User *const, vector<Movie> *, string, int);
template Episode LibraryContainer::getMedia(User *const, vector<Episode> *, string, int);
template Song LibraryContainer::getMedia(User *const, vector<Song> *, string, int);
template Ebook LibraryContainer::getMedia(User *const, vector<Ebook> *, string, int);
template <typename T>
T LibraryContainer::getMedia(User *const user, vector<T> *mediaContainer, string title, int releaseYear) {
  try {
    typename vector<T>::iterator media;

    for (media = mediaContainer->begin(); media != mediaContainer->end(); media++) {
      if (media->title == title && media->releaseYear == releaseYear) {
        if (media->getOwner() != user->getUsername() && !user->isAdmin())
          throw "Brak wymaganych uprawnien do odczytytania zawartosci tego zasobu!";

        return *media;
      }
    }

    throw "Nie znaleziono elementu w bibliotece!";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
    return T("error", 0, "error", "error", true, {});
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void LibraryContainer::printUserMedia(User *const user) {
  MediaElement *media  = nullptr;
  unsigned int counter = 0;

  for (auto &movie : movies) {
    media = &movie;

    if (media->getOwner() == user->getUsername()) {
      media->print();
      cout << endl;
      counter++;
    }
  }

  for (auto &episode : episodes) {
    media = &episode;

    if (media->getOwner() == user->getUsername()) {
      media->print();
      cout << endl;
      counter++;
    }
  }

  for (auto &song : songs) {
    media = &song;

    if (media->getOwner() == user->getUsername()) {
      media->print();
      cout << endl;
      counter++;
    }
  }

  for (auto &ebook : ebooks) {
    media = &ebook;

    if (media->getOwner() == user->getUsername()) {
      media->print();
      cout << endl;
      counter++;
    }
  }

  cout << "Laczna ilosc multimediow dla [" << user->getDisplayName() << "]: " << counter << endl;
  media = nullptr;
  delete media;
}

template void LibraryContainer::removeMedia(User *const, vector<Movie> *, string, int);
template void LibraryContainer::removeMedia(User *const, vector<Episode> *, string, int);
template void LibraryContainer::removeMedia(User *const, vector<Song> *, string, int);
template void LibraryContainer::removeMedia(User *const, vector<Ebook> *, string, int);
template <typename T>
void LibraryContainer::removeMedia(User *const user, vector<T> *mediaContainer, string title, int releaseYear) {
  try {
    typename vector<T>::iterator media;

    for (media = mediaContainer->begin(); media != mediaContainer->end(); media++) {
      if (media->title == title && media->releaseYear == releaseYear) {
        if (media->getOwner() != user->getUsername() && !user->isAdmin())
          throw "Brak wymaganych uprawnien do zarzadzania tym zasobem!";

        cout << "Usunieto [" << media->title << "(" << media->releaseYear << ")]\n";
        mediaContainer->erase(media);
        return;
      }
    }

    throw "Nie znaleziono elementu w bibliotece!";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

template void LibraryContainer::editMetadata(User *const, vector<Movie> *, string, int, MovieMetadata);
template void LibraryContainer::editMetadata(User *const, vector<Episode> *, string, int, EpisodeMetadata);
template void LibraryContainer::editMetadata(User *const, vector<Song> *, string, int, SongMetadata);
template void LibraryContainer::editMetadata(User *const, vector<Ebook> *, string, int, EbookMetadata);
template <typename T, typename M>
void LibraryContainer::editMetadata(User *const user, vector<T> *mediaContainer, string title, int releaseYear,
                                    M metadata) {
  try {
    typename vector<T>::iterator media;

    for (media = mediaContainer->begin(); media != mediaContainer->end(); media++) {
      if (media->title == title && media->releaseYear == releaseYear) {
        if (media->getOwner() != user->getUsername() && !user->isAdmin())
          throw "Brak wymaganych uprawnien do zarzadzania tym zasobem!";

        media->setMetadata(metadata);
        return;
      }
    }

    throw "Nie znaleziono elementu w bibliotece!";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

Album LibraryContainer::getAlbum(Song song) {
  Album album(song);

  for (auto &s : songs) {
    if (song.getMetadata().album == song.getMetadata().album)
      album.addTrack(s);
  }

  return album;
}

template void LibraryContainer::setVisibility(User *const user, vector<Movie> *, string, int, bool);
template void LibraryContainer::setVisibility(User *const user, vector<Episode> *, string, int, bool);
template void LibraryContainer::setVisibility(User *const user, vector<Song> *, string, int, bool);
template void LibraryContainer::setVisibility(User *const user, vector<Ebook> *, string, int, bool);
template <typename T>
void LibraryContainer::setVisibility(User *const user, vector<T> *mediaContainer, string title, int releaseYear,
                                     bool visibility) {
  try {
    typename vector<T>::iterator media;

    for (media = mediaContainer->begin(); media != mediaContainer->end(); media++) {
      if (media->title == title && media->releaseYear == releaseYear) {
        if (media->getOwner() != user->getUsername() && !user->isAdmin())
          throw "Brak wymaganych uprawnien do zarzadzania tym zasobem!";

        media->setVisibility(visibility);
        return;
      }
    }

    throw "Nie znaleziono elementu w bibliotece!";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

template <typename T> unsigned int LibraryContainer::countUserMedia(User *const user, vector<T> *mediaContainer) {
  typename vector<T>::iterator media;

  unsigned int counter = 0;

  for (media = mediaContainer->begin(); media != mediaContainer->end(); media++) {
    if (media->getOwner() == user->getUsername())
      counter++;
  }

  return counter;
}

unsigned int LibraryContainer::countUserLibrary(User *const user) {
  unsigned int counter = 0;

  counter += countUserMedia(user, getMovies());
  counter += countUserMedia(user, getEpisodes());
  counter += countUserMedia(user, getSongs());
  counter += countUserMedia(user, getEbooks());

  return counter;
}

void LibraryContainer::clear() {
  movies.clear();
  episodes.clear();
  songs.clear();
  ebooks.clear();
}

CSV LibraryContainer::generateCSV() {
  CSV csv;

  csv.header("Movies");
  for (auto &movie : movies)
    csv << movie.generateCSV();

  csv.header("Episodes");
  for (auto &movie : episodes)
    csv << movie.generateCSV();

  csv.header("Songs");
  for (auto &movie : songs)
    csv << movie.generateCSV();

  csv.header("Ebooks");
  for (auto &movie : ebooks)
    csv << movie.generateCSV();

  return csv;
}

void LibraryContainer::parseData(string line, MEDIA_TYPE header) {
  string::iterator head = line.begin();

  User fakeUser("fake", "fake", "FAKE", true);

  string bufor;
  MediaMetadata mediaMetadata;

  mediaMetadata.title        = CSV::extractString(line, head);
  mediaMetadata.releaseYear  = stoi(CSV::extractString(line, head));
  mediaMetadata.path         = CSV::extractString(line, head);
  mediaMetadata.owner        = CSV::extractString(line, head);
  mediaMetadata.publicAccess = (CSV::extractString(line, head) == "1" ? true : false);


  MovieMetadata movieMetadata;
  EpisodeMetadata episodeMetadata;
  SongMetadata songMetadata;
  EbookMetadata ebookMetadata;

  string actor, character;

  switch (header) {
  case MOVIE:
    movieMetadata.length      = stoi(CSV::extractString(line, head));
    movieMetadata.genere      = CSV::extractString(line, head);
    movieMetadata.releaseDate = CSV::extractString(line, head);

    while (head != line.end()) {
      actor     = CSV::extractString(line, head);
      character = CSV::extractString(line, head);

      movieMetadata.cast.push_back(pair(actor, character));
    }

    fakeUser.forceUsername(mediaMetadata.owner);
    addMedia(&fakeUser, mediaMetadata.title, mediaMetadata.releaseYear, mediaMetadata.path, mediaMetadata.publicAccess,
             movieMetadata);
    break;
  case EPISODE:
    episodeMetadata.length        = stoi(CSV::extractString(line, head));
    episodeMetadata.genere        = CSV::extractString(line, head);
    episodeMetadata.releaseDate   = CSV::extractString(line, head);
    episodeMetadata.series        = CSV::extractString(line, head);
    episodeMetadata.seasonNumber  = stoi(CSV::extractString(line, head));
    episodeMetadata.episodeNumber = stoi(CSV::extractString(line, head));

    while (head != line.end()) {
      actor     = CSV::extractString(line, head);
      character = CSV::extractString(line, head);

      episodeMetadata.cast.push_back(pair(actor, character));
    }

    fakeUser.forceUsername(mediaMetadata.owner);
    addMedia(&fakeUser, mediaMetadata.title, mediaMetadata.releaseYear, mediaMetadata.path, mediaMetadata.publicAccess,
             episodeMetadata);
    break;
  case SONG:
    songMetadata.length      = stoi(CSV::extractString(line, head));
    songMetadata.genere      = CSV::extractString(line, head);
    songMetadata.releaseDate = CSV::extractString(line, head);
    songMetadata.artist      = CSV::extractString(line, head);
    songMetadata.album       = CSV::extractString(line, head);
    songMetadata.trackNumber = stoi(CSV::extractString(line, head));

    fakeUser.forceUsername(mediaMetadata.owner);
    addMedia(&fakeUser, mediaMetadata.title, mediaMetadata.releaseYear, mediaMetadata.path, mediaMetadata.publicAccess,
             songMetadata);
    break;
  case EBOOK:
    ebookMetadata.numberOfPages = stoi(CSV::extractString(line, head));
    ebookMetadata.genere        = CSV::extractString(line, head);
    ebookMetadata.releaseDate   = CSV::extractString(line, head);
    ebookMetadata.author        = CSV::extractString(line, head);

    fakeUser.forceUsername(mediaMetadata.owner);
    addMedia(&fakeUser, mediaMetadata.title, mediaMetadata.releaseYear, mediaMetadata.path, mediaMetadata.publicAccess,
             ebookMetadata);
    break;
  }
}

void LibraryContainer::saveData() {
  try {
    ofstream file;
    file.open("library.csv");
    if (!file.is_open())
      throw "Zapisywanie zawartosci biblioteki nie powiodlo sie!";

    file << generateCSV();

    file.close();
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void LibraryContainer::readData() {
  try {
    ifstream file;
    file.open("library.csv");
    if (!file.is_open())
      throw "Wczytywanie zawartosci biblioteki nie powiodlo sie!";

    string line;
    MEDIA_TYPE header;

    while (!file.eof()) {
      getline(file, line);

      if (line[0] == '[' && line[line.length() - 1] == ']') {
        // cout << "Found Header: " << line << endl;

        if (line == "[Movies]")
          header = MOVIE;
        else if (line == "[Episodes]")
          header = EPISODE;
        else if (line == "[Songs]")
          header = SONG;
        else if (line == "[Ebooks]")
          header = EBOOK;
        else
          throw "Nieznany naglowek w pliku biblioteki!";
      }

      if (line.length() > 0 && line[line.length() - 1] == ';') {
        // cout << "Parsing: " << FG_YELLOW << line << CLEAR << endl;
        parseData(line, header);
      }
    }

    file.close();
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}