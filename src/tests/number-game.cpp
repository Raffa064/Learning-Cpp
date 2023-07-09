#include <iostream>

using namespace std;

const int difficult[] = {10, 100, 1000};

void rand(int, int &);

void numberGame() {
  cout << "\033[33mWhat difficult level do you want?\033[37m" << endl;
  cout << "\033[32m1) Easy\033[37m" << endl;
  cout << "\033[33m2) Normal\033[37m" << endl;
  cout << "\033[31m3) Hard\033[37m" << endl;
  cout << "\033[36mCtrl + c to exit any time!\033[37m" << endl;

  int level;
  cin >> level;

  level--;
  level %= 3;

  while (true) {
    system("clear");

    int a, b, x;
    rand(difficult[level], a);
    rand(difficult[level], b);
    x = a * b;

    cout << "\033[32m" << a << "\033[33m * \033[32m" << b
         << "\033[33m = \033[34mx \033[37m" << endl;
    cout << "\033[36mWhat's the value of x? \033[34m";

    int n;
    cin >> n;
    cout << "\033[37m";

    if (n == x) {
      cout << "\033[32mCorrect answer!\033[37m" << endl;
    } else {
      cout << "\033[31mWrong answer!\033[37m" << endl;
      cout << "The correct value is \033[34m" << x << "\033[37m!" << endl;
    }

    system("sleep 1");
  }
}

void rand(int max, int &x) {
  int i; // Variável iniciada sem passar valor == valor aleatório
  x = abs((random() + i) % max);
}