#include <iostream>

using namespace std;

void switches() {
  char input;
  bool alreadyChoose;

  do {
    cout << "Choose a character from A to D: ";
    cin >> input;

    alreadyChoose = true;

    switch (input) {
    case 'a':
    case 'A':
      cout << "Always" << endl;
      break;
    case 'b':
    case 'B':
      cout << "Bee" << endl;
      break;
    case 'c':
    case 'C':
      cout << "Cow" << endl;
      break;
    case 'd':
    case 'D':
      cout << "Dice" << endl;
      break;
    default:
      alreadyChoose = false;
      break;
    }
  } while (!alreadyChoose);

  cout << "Finished: " << input << endl;
}
