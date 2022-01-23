#ifndef JIPP2_USER_H
#define JIPP2_USER_H

#include "Csv.h"
#include "colors.h"
#include <string>

using namespace std;


class User {
private:
  string username;
  string password;

  string displayName;
  bool admin;

public:
  /**
   * @brief Tworzy nowy obiekt klasy User
   *
   * @param username
   * @param password
   * @param displayName
   * @param admin
   */
  User(string username, string password, string displayName, bool admin)
      : username(username), password(password), displayName(displayName), admin(admin) {}

  /**
   * @brief Wyświetla informacje o użytkowniku
   *
   */
  void print();

  /**
   * @brief Ustawia nazwę wyświetlana użytkownika
   *
   * @param newDisplayName Nazwa wyświetlania
   */
  void setDisplayName(string newDisplayName);

  /**
   * @brief Ustawia hasło klienta
   *
   * @param newPassowrd Hasło
   */
  void setPassword(string newPassowrd);

  /**
   * @brief Tworzy obiekt CSV przechowujący dane tego obiektu
   *
   * @return Obiekt CSV przechowujący dane tego obiektu
   */
  CSV generateCSV();

  /**
   * @brief Ustawia prawa administratora
   *
   * @param newStatus
   */
  void setAdminStatus(bool newStatus) { admin = newStatus; }

  /**
   * @brief Sprawdza czy przekazane hasło jest poprawne
   *
   * @param passwd Hało
   * @return True jeśli hasło jest poprawne
   */
  bool authenticate(string passwd) { return (password == passwd); }

  /**
   * @brief Pobiera nazwę użytkownika
   *
   * @return Nazwa użytkownika
   */
  string getUsername() { return username; }

  /**
   * @brief Pobiera nazwę wyświetlania użytkownika
   *
   * @return Nazwa wyświetlania
   */
  string getDisplayName() { return displayName; }

  /**
   * @brief Sprawdza czy użytkownika ma prawa administratora
   *
   * @return True jeśli użytkownik jest administratorem
   */
  bool isAdmin() { return admin; }

  /**
   * @brief Ustawia nazwę użytkownika
   *
   * @param newUsername Nazwa użytkownika
   */
  void forceUsername(string newUsername) { username = newUsername; }
};

#endif