#include "menu.h"


/**
 * @brief Demostruje możliwości programu
 *
 */
void demoMode() {
  UserContainer users;
  LibraryContainer library(2, 20);
  User *activeUser = nullptr;


  cout << bgWhite(cBlack(bold("Dodaje nowych uzytkownikow"))) << endl;

  users.addUser("user", "user", "Uzytkownik", false);
  users.addUser("admin", "admin", "Administrator", true);

  users.print();


  cout << endl << bgWhite(cBlack(bold("\"Loguje\" sie jako [user]"))) << endl;

  activeUser = users.getUser("user", "user");
  if (activeUser == nullptr)
    exit(EXIT_FAILURE);

  activeUser->print();


  cout << endl << bgWhite(cBlack(bold("Zmieniam nazwe wyswietlania uzytkownika"))) << endl;
  activeUser->setDisplayName("User");

  activeUser->print();


  cout << endl << bgWhite(cBlack(bold("Dodaje filmy do biblioteki"))) << endl;
  library.addMedia(activeUser, "Film #1", 2019, "./movies/film.1.mkv", false,
                   MovieMetadata{3843, "Akcja", "01.01.2019", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}});
  library.addMedia(activeUser, "Film #2", 2022, "./movies/film.2.mkv", true,
                   MovieMetadata{4248, "Akcja", "15.11.2022", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}});

  library.print(activeUser);


  cout << endl << bgWhite(cBlack(bold("Przekraczam limit filmow w bibliotece dla tego uzytkownika"))) << endl;

  library.addMedia(activeUser, "Film #3", 2000, "./movies/film.3.mkv", false,
                   MovieMetadata{3843, "Akcja", "01.01.2019", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}});


  cout << endl << bgWhite(cBlack(bold("Usuwam film do biblioteki"))) << endl;

  library.removeMedia(activeUser, library.getMovies(), "Film #1", 2019);

  library.print(activeUser);


  cout << endl << bgWhite(cBlack(bold("Edytuje metadane filmu"))) << endl;

  library.editMetadata(activeUser, library.getMovies(), "Film #2", 2022,
                       MovieMetadata{3412, "Historyczny", "19.07.2019", {{"Aktor #4", "Postac #16"}}});

  library.print(activeUser);


  cout << endl << bgWhite(cBlack(bold("Zmieniam publicznosc filmu"))) << endl;

  library.setVisibility(activeUser, library.getMovies(), "Film #2", 2022, false);

  library.print(activeUser);


  cout << endl << bgWhite(cBlack(bold("Sprawdzam dzialanie praw dostepu"))) << endl;

  users.addUser("second_user", "user", "Inny Uzytkownik", false);
  activeUser = users.getUser("second_user", "user");

  activeUser->print();

  library.removeMedia(activeUser, library.getMovies(), "Film #2", 2022);


  cout << endl << bgWhite(cBlack(bold("Dodaje pozostale media do biblioteki"))) << endl;

  library.setLimits(10, 50);

  library.addMedia(
      activeUser, "Epizod Serial 1-1", 2022, "./episodes/epizod.ADASD.mkv", true,
      EpisodeMetadata{
          1236, "Akcja", "15.11.2022", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}, "Serial #1", 1, 1});
  library.addMedia(
      activeUser, "Epizod Serial 1-2", 2022, "./episodes/epizod.ADASD.mkv", true,
      EpisodeMetadata{
          1236, "Akcja", "15.11.2022", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}, "Serial #1", 1, 2});
  library.addMedia(
      activeUser, "Epizod Serial 1-3", 2022, "./episodes/epizod.ADASD.mkv", true,
      EpisodeMetadata{
          1236, "Akcja", "15.11.2022", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}, "Serial #1", 1, 3});
  library.addMedia(
      activeUser, "Epizod Serial 2-1", 2022, "./episodes/epizod.ADASD.mkv", true,
      EpisodeMetadata{
          1236, "Akcja", "15.11.2022", {{"Aktor #1", "Postac #1"}, {"Aktor #2", "Postac #2"}}, "Serial #2", 1, 1});

  library.addMedia(activeUser, "Afterthoughts", 2022, "./music/a.mp3", true,
                   SongMetadata{152, "Classical", "14.01.2022", "Blue Box", "Dreams", 1});
  library.addMedia(activeUser, "Street", 2022, "./music/s.mp3", true,
                   SongMetadata{210, "Classical", "14.01.2022", "Blue Box", "Dreams", 2});
  library.addMedia(activeUser, "Temple", 2022, "./music/t.mp3", true,
                   SongMetadata{191, "Classical", "14.01.2022", "Blue Box", "Dreams", 3});
  library.addMedia(activeUser, "Spite", 2022, "./music/s.mp3", true,
                   SongMetadata{163, "Classical", "14.01.2022", "Blue Box", "Dreams", 4});
  library.addMedia(activeUser, "Elessar", 2022, "./music/e.mp3", true,
                   SongMetadata{248, "Classical", "14.01.2022", "Blue Box", "Dreams", 5});
  library.addMedia(activeUser, "Place", 2022, "./music/p.mp3", true,
                   SongMetadata{204, "Classical", "14.01.2022", "Blue Box", "Dreams", 6});
  library.addMedia(activeUser, "Winning", 2022, "./music/w.mp3", true,
                   SongMetadata{159, "Classical", "14.01.2022", "Blue Box", "Dreams", 7});
  library.addMedia(activeUser, "Feeling", 2022, "./music/f.mp3", true,
                   SongMetadata{228, "Classical", "14.01.2022", "Blue Box", "Dreams", 8});
  library.addMedia(activeUser, "Know", 2022, "./music/k.mp3", true,
                   SongMetadata{166, "Classical", "14.01.2022", "Blue Box", "Dreams", 9});
  library.addMedia(activeUser, "Time", 2022, "./music/t.mp3", true,
                   SongMetadata{225, "Classical", "14.01.2022", "Blue Box", "Dreams", 10});

  library.addMedia(activeUser, "Book #1", 2022, "./music/b.pub", true,
                   EbookMetadata{225, "Book", "01.01.2022", "Author #1"});
  library.addMedia(activeUser, "Book #2", 2022, "./music/b.pub", true,
                   EbookMetadata{225, "Book", "01.01.2022", "Author #1"});
  library.addMedia(activeUser, "Book #3", 2022, "./music/b.pub", true,
                   EbookMetadata{225, "Book", "01.01.2022", "Author #2"});

  library.print(activeUser);


  cout << endl << bgWhite(cBlack(bold("Zapisywanie uzytkownikow i biblioteki"))) << endl;

  library.saveData();
  users.saveData();


  library.clear();
  library.print(activeUser);

  activeUser = nullptr;
  users.clear();
  users.print();


  cout << endl << bgWhite(cBlack(bold("Wczytywanie uzytkownikow i biblioteki"))) << endl;

  library.readData();
  users.readData();

  activeUser = users.getUser("admin", "admin");

  users.print();
  library.print(activeUser);


  cout << endl << bgWhite(cBlack(bold("Pobieram utwor z biblioteki"))) << endl;

  Song s = library.getMedia(activeUser, library.getSongs(), "Spite", 2022);
  s.print();


  cout << endl << bgWhite(cBlack(bold("Wyswietlam lokalizacje zasobu"))) << endl;

  library.getMedia(activeUser, library.getMovies(), "Film #2", 2022).printLocation();
  library.getMedia(activeUser, library.getEpisodes(), "Epizod Serial 1-3", 2022).printLocation();
  library.getMedia(activeUser, library.getSongs(), "Spite", 2022).printLocation();
  library.getMedia(activeUser, library.getEbooks(), "Book #1", 2022).printLocation();


  cout << endl << bgWhite(cBlack(bold("Wyswietlam zasoby aktualnego uzytkownika"))) << endl;

  activeUser = users.getUser("second_user", "user");
  library.printUserMedia(activeUser);


  cout << endl << bgWhite(cBlack(bold("Pobieram album na podstawie utworu"))) << endl;
  Album album = library.getAlbum(s);
  album.print();

  activeUser = nullptr;
  delete activeUser;
}

/**
 * @brief Renejstruje nowego uzytkownika
 *
 * @param users
 */
void registerUser(UserContainer &users) {
  string username, displayName, password, buf;
  bool admin;

  cout << bgCyan("Rejestrowanie nowego uzytkownika") << endl;

  cout << "Nazwa uzytkownika: ";
  cin >> username;

  cout << "Nazwa wyswietlania: ";
  cin >> displayName;

  cout << "Haslo: ";
  cin >> password;

  cout << "Administrator [T/N]: ";
  cin >> buf;

  if (buf == "T" || buf == "t")
    admin = true;
  else
    admin = false;

  users.addUser(username, password, displayName, admin);
}

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addMovie(User *activeUser, LibraryContainer &library) {
  string title, path, buf;
  int releaseYear;
  bool isPublic;

  cout << bgCyan("Dodawanie nowego filmu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  cout << "Sciezka: ";
  cin >> path;

  cout << "Publiczny [T/N]: ";
  cin >> buf;

  if (buf == "T" || buf == "t")
    isPublic = true;
  else
    isPublic = false;

  library.addMedia(activeUser, title, releaseYear, path, isPublic, MovieMetadata{});
}

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addEpisode(User *activeUser, LibraryContainer &library) {
  string title, path, buf;
  int releaseYear;
  bool isPublic;

  cout << bgCyan("Dodawanie nowego epizodu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  cout << "Sciezka: ";
  cin >> path;

  cout << "Publiczny [T/N]: ";
  cin >> buf;

  if (buf == "T" || buf == "t")
    isPublic = true;
  else
    isPublic = false;

  library.addMedia(activeUser, title, releaseYear, path, isPublic, EpisodeMetadata{});
}

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addSong(User *activeUser, LibraryContainer &library) {
  string title, path, buf;
  int releaseYear;
  bool isPublic;

  cout << bgCyan("Dodawanie nowego utworu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  cout << "Sciezka: ";
  cin >> path;

  cout << "Publiczny [T/N]: ";
  cin >> buf;

  if (buf == "T" || buf == "t")
    isPublic = true;
  else
    isPublic = false;

  library.addMedia(activeUser, title, releaseYear, path, isPublic, SongMetadata{});
}

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addEbook(User *activeUser, LibraryContainer &library) {
  string title, path, buf;
  int releaseYear;
  bool isPublic;

  cout << bgCyan("Dodawanie nowego ebooka") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  cout << "Sciezka: ";
  cin >> path;

  cout << "Publiczny [T/N]: ";
  cin >> buf;

  if (buf == "T" || buf == "t")
    isPublic = true;
  else
    isPublic = false;

  library.addMedia(activeUser, title, releaseYear, path, isPublic, EbookMetadata{});
}

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeMovie(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Usuwanie filmu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  library.removeMedia(activeUser, library.getMovies(), title, releaseYear);
}

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeEpisode(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Usuwanie epizodu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  library.removeMedia(activeUser, library.getEpisodes(), title, releaseYear);
}

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeSong(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Usuwanie utworu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  library.removeMedia(activeUser, library.getSongs(), title, releaseYear);
}

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeEbook(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Usuwanie ebooka") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  library.removeMedia(activeUser, library.getEbooks(), title, releaseYear);
}

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printAlbum(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Wyswietlanie albumu utworu") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  Song media = library.getMedia(activeUser, library.getSongs(), title, releaseYear);
  library.getAlbum(media).print();
}

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printMovie(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Wyswietlanie informacji o filmie") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  Movie media = library.getMedia(activeUser, library.getMovies(), title, releaseYear);
  media.print();
}

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printEpisode(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Wyswietlanie informacji o epizodzie") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  Episode media = library.getMedia(activeUser, library.getEpisodes(), title, releaseYear);
  media.print();
}

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printSong(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Wyswietlanie informacji o utworze") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  Song media = library.getMedia(activeUser, library.getSongs(), title, releaseYear);
  media.print();
}

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printEbook(User *activeUser, LibraryContainer &library) {
  string title;
  int releaseYear;

  cout << bgCyan("Wyswietlanie informacji o ebooku") << endl;

  cout << "Tytul: ";
  cin >> title;

  cout << "Rok wydania: ";
  cin >> releaseYear;

  Ebook media = library.getMedia(activeUser, library.getEbooks(), title, releaseYear);
  media.print();
}

/**
 * @brief Zmienia nawe wyswietlania uzytkownika
 *
 * @param activeUser
 */
void changeDisplayname(User *activeUser) {
  string displayName;

  cout << bgCyan("Zmiana nazwy wyswietlania uzytkownika") << endl;

  cout << "Nazwa wyswietlania: ";
  cin >> displayName;

  activeUser->setDisplayName(displayName);
}

/**
 * @brief Loguje sie jako uzytkownik
 *
 * @param users Kontener uzytkownikow
 * @return Uzytkownik
 */
User *loginUser(UserContainer &users) {
  string username, password;

  cout << endl;
  cout << bgCyan("Logowanie") << endl;

  cout << "Nazwa uzytkownika: ";
  cin >> username;

  cout << "Haslo: ";
  cin >> password;

  return users.getUser(username, password);
}

/**
 * @brief Zmienia prawa uzytkownika
 *
 * @param activeUser
 */
void changeAdmin(User *activeUser) {
  string buf;
  bool admin;

  cout << bgCyan("Zmiana praw uzytkownika") << endl;

  cout << "Administrator [T/N]: ";
  cin >> buf;

  if (buf == "T" || buf == "t")
    admin = true;
  else
    admin = false;

  activeUser->setAdminStatus(admin);
}

/**
 * @brief Wyswietla menu programu
 *
 */
void printMenuOptions() {
  cout << cBlack(bgWhite("Menu programu")) << endl;

  cout << "1. Dodaj uzytkownika\n"
          "2. Zmien uzytkownika\n"
          "3. Zmien nazwe wyswietlania\n"
          "4. Zmien prawa administratora\n\n"

          "5. Dodaj film\n"
          "6. Dodaj epizod\n"
          "7. Dodaj utwor\n"
          "8. Dodaj ebook\n\n"

          "9. Modyfikuj film\n"
          "10. Modyfikuj epizod\n"
          "11. Modyfikuj utwor\n"
          "12 Modyfikuj ebook\n\n"

          "13. Usun film\n"
          "14. Usun epizod\n"
          "15. Usun utwor\n"
          "16. Usun ebook\n\n"

          "17. Wyswietl zawartosc biblioteki\n"
          "18. Wyswietl zasoby uzytkownika\n\n"

          "19. Wyswietl informacje o filmie\n"
          "20. Wyswietl infirmacje o epizodzie\n"
          "21. Wyswiel informacje o utworze\n"
          "22. Wyswietl informacje o ebooku\n\n"

          "23. Wyswietl album utworu\n\n"

          "24. Zapisz dane\n"
          "25. Wczytaj dane\n\n"

          "26. Wyswietl informacje o aktywnym uzytkowniku\n\n"

          "0. Zakoncz program\n";
}
