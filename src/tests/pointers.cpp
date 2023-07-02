#include <iostream>

using namespace std;

/*
  Memoria Stack
  Usada para armazenar variáveis e parâmetros,
  a memoria stack é alocada automaticamente.

  ex:

  void sum(int a, int b) {
    return a + b;
  }

  essa função possui 2 variáveis int, portanto, vai ter
  8 bytes alocados na memoria stack;

  MEMORIA HEAP
  Memoria dinâmica, é usada e gerenciada de acordo
  com o programador, a partir do new e delete.

  ex:

  int sum(int a, int b) {
    int *pointer = new int;

    int &sum = *pointer;
    sum = a + b;

    return sum;
  }

  vai ser alocado 4 byte na memoria para armazenar o valor
  da variável sum, e esse valor vai ficar la até o programa
  acabar, pois ele não foi desalocado, paraparapara resolver isso:

  int* sum(int a, int b) {
    int *pointer = new int;

    int &sum = *pointer;
    sum = a + b;

    return pointer;
  }

  int* pointer = sum(x, y);
  delete pointer;  // desaloca a memoria usada pela soma

*/

void printPointer(int *pointer) { cout << "Pointer: " << pointer << endl; }

void printReference(int &pointer) { cout << "Reference: " << pointer << endl; }

void pointers() {
  int x = 64;

  int *pointer = &x;         // Ponteiro para a referencia de x (leia a OBS)
  int &reference = *pointer; // Referencia do ponteiro de x

  printPointer(pointer);
  printReference(reference);
  printReference(x); // x é uma referencia implícita!
}

/*
 OBS:
  int *pointer = &x;

  O uso de "&" é necessário por que "x" na forma padrão
  retora o valor 64 ao invés da sua referencia.
*/