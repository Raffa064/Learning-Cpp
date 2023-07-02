#include <iostream>

using namespace std;

/*
  No C++, a leitura do código é de cima pra baixo
  e por isso, uma função não consegue acessar outra que
  foi declarada após ela mesma.

  A solução disso é criar protótipos, que são uma
  declaração sem escopo da função.
*/

void prototypeFunction();      // protótipo
void prototypeFunction(int n); // protótipo da versão sobrecarregada

void prototype() {
  prototypeFunction();

  prototypeFunction(5);
}

void prototypeFunction() { cout << "Função com protótipo!" << endl; }

// Função sobrecarregada
void prototypeFunction(int n) {
  for (int i = 0; i < n; i++)
    prototypeFunction();
}