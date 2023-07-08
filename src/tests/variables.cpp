#include <iostream>

using namespace std;

void variables() {
  // i é um numero aleatório pq acredite ou não...
  // variáveis iniciam com o valor q tava na memoria na
  // qual ela for alocada kkk

  int i;
  cout << "Undefined integer: " << i << endl;

  unsigned int j = -4; // Unsigned não permite negativos, então isso da vira
                       // total o numero inteiro máximo menos 4
  cout << "Negative value on a \033[33munsigned int\033[37m]: " << j << endl;

  char character = 'R';
  char string[7] = "Rafael"; // o index é 7 e a string tem 6 dígitos, pq ela
                             // obrigatoriamente termina em \0

  std::string str = "ABCDEFGHIJKLM";
  str += "NOPQRSTUVWXYZ";
  cout << "Concatented string: " << str << endl;

  // Essa é a notação de array do c++
  bool boolArray[2] = {true, false};

  cout << "Bool array: " << boolArray << endl;
}