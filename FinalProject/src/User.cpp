#include "User.h"


void User::print() {
  cout << FG_GREEN << "Dane uzytkownika:" << CLEAR << "\n   username: " << username
       << "\n   displayName: " << displayName << "\n   admin: " << (admin ? "true" : "false") << endl;
}

void User::setDisplayName(string newDisplayName) {
  if (displayName == newDisplayName)
    throw "Nowa nazwa wyswietalania jest taka sama jak obecnie uzywana!";

  displayName = newDisplayName;
}

void User::setPassword(string newPassowrd) {
  if (password == newPassowrd)
    throw "Nowe haslo musi roznic sie od obecnie uzywanego!";

  password = newPassowrd;
}

CSV User::generateCSV() {
  CSV csv;

  csv << username;
  csv << password;
  csv << displayName;
  csv << admin;

  return csv;
}