#include <iostream>

using namespace std;

/*
  Tanto ++ quanto -- aplicam incremento/decremento,
  mas quando colocados antes da variável, a expressão assume o resultado
  imediatamente, e quando colocada após, a expressão vai retornar o valor
  antigo da variável antes do incremento/decremento.

  EX:

  int x = 5;
  cout << (x++) == 5 << endl; // true

  int y = 10;
  cout << (++x) == 10 << endl; // false

*/

void incremental() {
  int x = 64;

  cout << "  X: " << x << endl;     // escreve x
  cout << "++X: " << ++x << endl;   // escreve x+1
  cout << "  X++: " << x++ << endl; // escreve x, e soma 1 depois
  cout << "  X: " << x << endl;     // escreve x
}