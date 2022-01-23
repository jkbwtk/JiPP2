#include "Album.h"
#include "Csv.h"
#include "Ebook.h"
#include "Episode.h"
#include "LibraryContainer.h"
#include "MediaElement.h"
#include "Movie.h"
#include "Song.h"
#include "User.h"
#include "UserContainer.h"
#include "colors.h"
#include <chrono>
#include <iostream>
#include <menu.h>
#include <string>
#include <thread>

using namespace std;


int main(int argc, char *argv[]) {
  if (argc >= 2 && string("demo") == argv[1]) {
    cout << bgGreen(bold("Uruchamiam program w trybie DEMO!")) << endl;
    demoMode();

    exit(EXIT_SUCCESS);
  }

  UserContainer users;
  LibraryContainer library(10, 20);
  User *activeUser = nullptr;

  // czyszczenie plików z danymi
  // users.saveData();
  // library.saveData();

  users.readData();
  library.readData();


  if (users.getSize() == 0) {
    this_thread::sleep_for(chrono::seconds(3));

    while (users.getSize() == 0) {
      system("cls");
      registerUser(users);
    }

    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
  }

  users.print();

  string username, password;

  while (activeUser == nullptr) {
    activeUser = loginUser(users);
  }

  cout << "Zalogowano jako [" << activeUser->getDisplayName() << "]\n";
  this_thread::sleep_for(chrono::seconds(1));

  bool loop  = true;
  int option = -1;

  do {
    system("cls");
    printMenuOptions();

    cout << ">";
    cin >> option;

    switch (option) {
    case 1:
      system("cls");
      registerUser(users);
      this_thread::sleep_for(chrono::seconds(1));

      break;
    case 2:
      system("cls");
      activeUser = nullptr;

      while (activeUser == nullptr) {
        activeUser = loginUser(users);
      }

      cout << "Zalogowano jako [" << activeUser->getDisplayName() << "]\n";
      this_thread::sleep_for(chrono::seconds(1));

      break;
    case 3:
      system("cls");

      changeDisplayname(activeUser);
      break;
    case 4:
      system("cls");
      changeAdmin(activeUser);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 5:
      system("cls");
      addMovie(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 6:
      system("cls");
      addEpisode(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 7:
      system("cls");
      addSong(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 8:
      system("cls");
      addEbook(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 13:
      system("cls");
      removeMovie(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 14:
      system("cls");
      removeEpisode(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 15:
      system("cls");
      removeSong(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 16:
      system("cls");
      removeEbook(activeUser, library);
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 17:
      system("cls");
      library.print(activeUser);

      getchar();
      getchar();

      break;

    case 18:
      system("cls");
      library.printUserMedia(activeUser);

      getchar();
      getchar();

      break;

    case 19:
      system("cls");
      printMovie(activeUser, library);

      getchar();
      getchar();

      break;

    case 20:
      system("cls");
      printEpisode(activeUser, library);


      getchar();
      getchar();

      break;

    case 21:
      system("cls");
      printSong(activeUser, library);


      getchar();
      getchar();

      break;

    case 22:
      system("cls");

      printEbook(activeUser, library);


      getchar();
      getchar();

      break;

    case 23:
      system("cls");

      printAlbum(activeUser, library);


      getchar();
      getchar();

      break;

    case 24:
      library.saveData();
      users.saveData();
      this_thread::sleep_for(chrono::seconds(1));

      break;


    case 25:
      library.readData();
      users.readData();
      this_thread::sleep_for(chrono::seconds(1));

      break;

    case 26:
      system("cls");
      activeUser->print();

      getchar();
      getchar();

      break;
    case 0:
      loop = false;
      break;

    default:
      cout << cRed("Bladna opcja!") << endl;
      this_thread::sleep_for(chrono::seconds(1));

      break;
    }
  } while (loop);

  activeUser = nullptr;
  delete activeUser;

  return 0;
}