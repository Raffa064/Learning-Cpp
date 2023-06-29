#include <cstdlib>
#include <iostream>

using namespace std;

void conditionals() {
  cout << "TESTE DE CONDICIONAIS" << endl;

  int i = random();

  if (i >= 0) {
    cout << i << " is greater than 0" << endl;
  } else if (i == 0) {
    cout << i << " is equals then 0" << endl;
  } else {
    cout << i << " is less than 0" << endl;
  }

  bool ex = 30 < 40 || i == 40; //Expressão booliana
}