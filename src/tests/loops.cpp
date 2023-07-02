#include <iostream>

using namespace std;

void loops() {
  int i = 0;
  while (i < 10) {
    cout << "WHILE: " << i << endl;
    i++;
  }

  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      cout << "number 5 skipped" << endl;
      continue;
    }

    if (i == 8) {
      cout << "number 8 breaks the loop" << endl;
      break;
    }

    cout << "FOR: " << i << endl;
  }

  int input;
  do {
    cout << "Enter a number greater than 10 to exit: ";
    cin >> input;
  } while (input < 10);
}