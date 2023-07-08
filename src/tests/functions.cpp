#include <iostream>

/*
  Esse código é uma visão geral de funções
*/

using namespace std;

// Protótipos
int mul(int, int);
int mul(int, int, int);
template <class Type> string typeName(Type);
int *createTable(int);
void printTable(int *);
void inverse(int &);

void functions() {
  cout << "3 * 2 = " << mul(3, 2) << endl;
  cout << "4 * 1 * 3 = " << mul(1, 2, 3) << endl;
  cout << "Type id of 64 is " << typeName(64) << endl;

  int *table = createTable(6);
  printTable(table);
  delete[] table;

  int value = 64;
  cout << "Value before: " << value << endl;
  inverse(value);
  cout << "Value after: " << value << endl;
}

int mul(int a, int b) { return a * b; }

// Overload (sobrecarga)
int mul(int a, int b, int c) { return a * b * c; }

// Templates (generics)
template <class Type> string typeName(Type any) { return typeid(any).name(); }

int *createTable(int n) {
  int *table = new int[11];
  table[0] = n;
  for (int i = 1; i <= 10; i++) {
    table[i] = n * i;
  }
  return table;
}

void printTable(int *table) {
  for (int i = 1; i <= 10; i++) {
    cout << table[0] << " x " << i << " = " << table[i] << endl;
  }
}

// Exemplo de uso de referências
void inverse(int &number) {
  // O parâmetro number deve ser uma variável obrigatoriamente

  number *= -1; // isso será aplicado a variável original
}