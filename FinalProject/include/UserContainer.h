#ifndef JIPP2_USERCONTAINER_H
#define JIPP2_USERCONTAINER_H

#include "Csv.h"
#include "User.h"
#include "colors.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;


class UserContainer {
private:
  map<string, User> users;

public:
  /**
   * @brief Wyswietla listę użytkowników
   *
   */
  void print();

  /**
   * @brief Dodaje użytkownika
   *
   * @param username Nazwa użytkownika
   * @param password Hasło
   * @param displayName Nazwa wyświetlania
   * @param admin Prawa administratora
   */
  void addUser(string username, string password, string displayName, bool admin);

  /**
   * @brief Usuwa użytkownika
   *
   * @param user Użytkownik wykonujący
   * @param username Nazwa użytkownika
   */
  void removeUser(User *const user, string username);

  /**
   * @brief Zmienia nazwę wyświetlania użytkownika
   *
   * @param user Użytkownik wykonujący
   * @param username Nazwa użytkownika
   * @param displayName Nazwa wyświetlania
   */
  void setDisplayName(User *const user, string username, string displayName);

  /**
   * @brief Zmienia hasło użytkownika
   *
   * @param user Użytkownik wykonujący
   * @param username Nazwa użytkownika
   * @param password Hasło
   */
  void setPassword(User *const user, string username, string password);

  /**
   * @brief Pobiera użytkownika
   *
   * @param username Nazwa użytkownika
   * @param password Hasło
   * @return Znacznik do użytkownika
   */
  User *getUser(string username, string password);

  /**
   * @brief Pobiera ilość użytkowników
   *
   * @return Ilość zarejestrowanych użytkownikow
   */
  int getSize() { return users.size(); }

  /**
   * @brief Tworzy obiekt CSV przechowujący dane tego obiektu
   *
   * @return Obiekt CSV przechowujący dane tego obiektu
   */
  CSV generateCSV();

  /**
   * @brief Usuwa wszystkich użytkowników
   *
   */
  void clear() { users.clear(); }

  /**
   * @brief Zapusje listę użytkowników do pliku
   *
   */
  void saveData();

  /**
   * @brief Wczytuje listę użytkowników z pliku
   *
   */
  void readData();
};

#endif