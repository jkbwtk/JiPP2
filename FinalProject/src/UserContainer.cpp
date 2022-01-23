#include "UserContainer.h"

void UserContainer::print() {
  cout << BG_GREEN FG_BLACK << "Zarejestrowanych uzytkownikow: " << users.size() << CLEAR << endl;

  for (auto &user : users) {
    user.second.print();
  }
}

void UserContainer::addUser(string username, string password, string displayName, bool admin) {
  try {
    if (users.contains(username))
      throw "Uzytkownik o takiej nazwie juz istnieje!";

    for (auto &user : users) {
      if (user.second.getDisplayName() == displayName)
        throw "Uzytkownik z taka nazwa wyswietlania juz istnieje!";
    }

    users.emplace(username, User(username, password, displayName, admin));
    cout << "Zarejestrowano uzytkownika [" << username << "]\n";
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void UserContainer::removeUser(User *const user, string username) {
  try {
    if (user->getUsername() == username)
      throw "Nie mozna usunac aktywnego uzytkownika!";

    if (user->isAdmin() == false)
      throw "Brak wymaganych uprawnien do usuniecia tego uzytkownika!";

    if (!users.contains(username))
      throw "Uzytkownik nie istnieje!";

    users.erase(username);
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void UserContainer::setDisplayName(User *const user, string username, string displayName) {
  try {
    if (user->getUsername() != username)
      if (user->isAdmin() == false)
        throw "Brak wymaganych uprawnien do modyfikowania tego uzytkownika!";

    if (!users.contains(username))
      throw "Uzytkownik nie istnieje!";

    User oldUser = users.at(username);
    oldUser.setDisplayName(displayName);
    users.erase(username);
    users.emplace(username, oldUser);
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void UserContainer::setPassword(User *const user, string username, string password) {
  try {
    if (user->getUsername() != username)
      if (user->isAdmin() == false)
        throw "Brak wymaganych uprawnien do modyfikowania tego uzytkownika!";

    if (!users.contains(username))
      throw "Uzytkownik nie istnieje!";

    User oldUser = users.at(username);
    oldUser.setPassword(password);
    users.erase(username);
    users.emplace(username, oldUser);
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

User *UserContainer::getUser(string username, string password) {
  try {
    if (!users.contains(username))
      throw "Uzytkownik nie istnieje!";

    if (!users.find(username)->second.authenticate(password))
      throw "Bledne haslo!";

    return &users.find(username)->second;
  } catch (const char *err) {
    cerr << cRed(err) << endl;

    return nullptr;
  }
}

CSV UserContainer::generateCSV() {
  CSV csv;

  for (auto &user : users)
    csv << user.second.generateCSV();

  return csv;
}

void UserContainer::saveData() {
  try {
    ofstream file;
    file.open("users.csv");
    if (!file.is_open())
      throw "Zapisywanie listy uzytkownikow nie powiodlo sie!";

    file << generateCSV();

    file.close();
  } catch (const char *err) {
    cerr << cRed(err) << endl;
  } catch (...) {
    cerr << "ERROR!" << endl;
    exit(EXIT_FAILURE);
  }
}

void UserContainer::readData() {
  try {
    ifstream file;
    file.open("users.csv");
    if (!file.is_open())
      throw "Wcztytywanie listy uzytkownikow nie powiodlo sie!";

    string line;
    string username, password, displayName;
    bool admin;

    while (!file.eof()) {
      getline(file, line);

      if (line.length() > 0 && line[line.length() - 1] == ';') {
        // cout << "Parsing: " << FG_YELLOW << line << CLEAR << endl;

        string::iterator head = line.begin();

        username    = CSV::extractString(line, head);
        password    = CSV::extractString(line, head);
        displayName = CSV::extractString(line, head);
        admin       = (CSV::extractString(line, head) == "1" ? true : false);

        addUser(username, password, displayName, admin);
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