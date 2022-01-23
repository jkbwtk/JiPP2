#ifndef JIPP2_MENU_H
#define JIPP2_MENU_H


#include "Album.h"
#include "Ebook.h"
#include "Episode.h"
#include "LibraryContainer.h"
#include "Movie.h"
#include "Song.h"
#include "User.h"
#include "UserContainer.h"
#include <string>

using namespace std;

/**
 * @brief Demostruje możliwości programu
 *
 */
void demoMode();

/**
 * @brief Renejstruje nowego uzytkownika
 *
 * @param users
 */
void registerUser(UserContainer &users);

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addMovie(User *activeUser, LibraryContainer &library);

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addEpisode(User *activeUser, LibraryContainer &library);

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addSong(User *activeUser, LibraryContainer &library);

/**
 * @brief Dodaje zasob do biblioteki
 *
 * @param activeUser
 * @param library
 */
void addEbook(User *activeUser, LibraryContainer &library);

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeMovie(User *activeUser, LibraryContainer &library);

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeEpisode(User *activeUser, LibraryContainer &library);

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeSong(User *activeUser, LibraryContainer &library);

/**
 * @brief Usuwa zasob z boblioteki
 *
 * @param activeUser
 * @param library
 */
void removeEbook(User *activeUser, LibraryContainer &library);

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printAlbum(User *activeUser, LibraryContainer &library);

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printMovie(User *activeUser, LibraryContainer &library);

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printEpisode(User *activeUser, LibraryContainer &library);

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printSong(User *activeUser, LibraryContainer &library);

/**
 * @brief Wyswietla informacje o zasobie
 *
 * @param activeUser
 * @param library
 */
void printEbook(User *activeUser, LibraryContainer &library);

/**
 * @brief Zmienia nawe wyswietlania uzytkownika
 *
 * @param activeUser
 */
void changeDisplayname(User *activeUser);

/**
 * @brief Loguje sie jako uzytkownik
 *
 * @param users Kontener uzytkownikow
 * @return Uzytkownik
 */
User *loginUser(UserContainer &users);

/**
 * @brief Zmienia prawa uzytkownika
 *
 * @param activeUser
 */
void changeAdmin(User *activeUser);

/**
 * @brief Wyswietla menu programu
 *
 */
void printMenuOptions();


#endif