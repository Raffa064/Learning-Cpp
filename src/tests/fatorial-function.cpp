#include <iostream>

using namespace std;

/*
  Isso aqui é um exemplo de recursividade
  Para quem não sabe, uma função recursiva basicamente
  é uma função que chama a si mesmo e trabalha num resultado
  a partir dos seus argumentos, como no caso da fatorial_recursive()
*/

void print(int (*)(int));
int fatorial_for(int);
int fatorial_recursive(int);

void fatorial() {
  cout << "Fatorial by for" << endl;
  print(*fatorial_for);

  cout << "Fatorial by recursion" << endl;
  print(*fatorial_recursive);
}

void print(int (*f)(int n)) {
  for (int i = 1; i <= 10; i++) {
    cout << i << "! = " << f(i) << endl;
  }
}

// Exemplo sem recursão
int fatorial_for(int n) {
  for (int i = n - 1; i >= 1; i--) {
    n *= i;
  }

  return n;
}

// Exemplo com recursão
int fatorial_recursive(int n) {
  if (n <= 1)
    return 1;
  return fatorial_recursive(n - 1) * n;
}