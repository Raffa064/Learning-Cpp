#include <iostream>

using namespace std;

void arrays() {
  int array[5] = {0, 0, 0, 0, 0};

  cout << "Acessando index inexistente do array: ";
  for (int i = 0; i < 5; i++) {
    // Index fora do range: sem exception, acessa memória indevida
    cout << array[i + 1] << ", ";
  }

  cout << endl;
}
