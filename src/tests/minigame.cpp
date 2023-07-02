#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

// <CHAT GPT>
// Essa parte eu precisei pegar do chatgpt, pq ncurses e conio não funciona no
// termux...

void setConsoleMode() {
  termios tty;
  tcgetattr(STDIN_FILENO, &tty);
  tty.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void restoreConsoleMode() {
  termios tty;
  tcgetattr(STDIN_FILENO, &tty);
  tty.c_lflag |= ICANON | ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

char readChar() {
  char ch;
  setConsoleMode();
  ch = getchar();
  restoreConsoleMode();
  return ch;
}
// </CHATGPT>

int distanceUnit(int x) {
  if (x != 0)
    return 0;

  if (x > 0)
    return 1;

  return -1;
}

void minigame() {
  int mapSize = 10;
  int map[mapSize][mapSize];

  for (int i = 0; i < mapSize; i++) {
    for (int j = 0; j < mapSize; j++) {
      map[i][j] = 0;
    }
  }

  int playerX = 0;
  int playerY = 0;
  int playerPoints = 0;
  int fruitX = rand() % mapSize;
  int fruitY = rand() % mapSize;
  char playerInput;

  bool running = true;
  while (running) {
    system("clear");

    for (int i = 0; i < mapSize; i++) {
      for (int j = 0; j < mapSize; j++) {
        string value;

        if (fruitX == j && fruitY == i) {
          value = "\033[31mO";
        } else if (playerX == j && playerY == i) {
          value = "\033[32mO";
        } else {
          value = " ";
        }

        if (playerX == fruitX && playerY == fruitY) {
          fruitX = rand() % mapSize;
          fruitY = rand() % mapSize;
          playerPoints++;
        }

        cout << "[" + value + "\033[37m]";
      }

      cout << endl;
    }

    cout << "\033[34mPoints: \033[33m" << playerPoints << "\033[37m" << endl;
    cout << "Press q to exit" << endl;

    playerInput = readChar();

    switch (playerInput) {
    case 'w':
      playerY--;
      break;
    case 's':
      playerY++;
      break;
    case 'a':
      playerY--;
      break;
    case 'd':
      playerX++;
      break;
    case 'h':
      playerX += distanceUnit(fruitX - playerX);
      playerY += distanceUnit(fruitY - playerY);
      cout << "\033[32m<<<< H4CK3R \033[36mM0D3\033[32m >>>>\033[37m" << endl;
      break;
    case 'g':
      playerX = fruitX;
      playerY = fruitY;
      cout << "\033[33m<<<< GOD \033[31mMODE\033[33m >>>>\033[37m" << endl;
      break;
    case 'q':
      running = false;
      break;
    default:
      cout << "\033[31m[ Invalid input ]\033[37m" << endl;
      break;
    }

    playerX = max(0, min(mapSize - 1, playerX));
    playerY = max(0, min(mapSize - 1, playerY));
  }
  cout << "Thanks for playing!" << endl;
}