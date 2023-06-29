#include <iostream>

using namespace std;

/*

OPERADORES MATEMÁTICOS:

UNÁRIOS:
-x          INVERTE SINAL
++x ou x++  INCREMENTO
--x ou x--  DECREMENTO


BINÁRIOS:
x + y   ADIÇÃO
x - y   SUBTRAÇÃO
x * y   MULTIPLICAÇÃO
x / y   DIVISÃO
x % y   MODULO

ATRIBUIÇÃO:
x += y    ADICIONADO
x -= y    SUBTRAÍDO
x *= y    MULTIPLICADO
x /= y    DIVIDIDO
x %= y    MODULO 

*/

void arithmetic() {
  float a;
  float b;
  int operation;
  float result;

  while (true) {
    do {
      system("clear");
      cout << "Select one operation: " << endl;
      cout << "1) ADD" << endl;
      cout << "2) SUB" << endl;
      cout << "3) MUL" << endl;
      cout << "4) DIV" << endl;
      cout << "5) MOD" << endl;
      cout << "OPERATION: ";
      cin >> operation;
    } while (operation <= 0 && operation > 5);

    cout << "Enter the value for A: ";
    cin >> a;

    cout << "Enter the value for B: ";
    cin >> b;

    switch (operation) {
    case 1:
      result = a + b;
      cout << "A + B = " << result << endl;
      break;
    case 2:
      result = a - b;
      cout << "A - B = " << result << endl;
    case 3:
      result = a * b;
      cout << "A * B = " << result << endl;
      break;
    case 4:
      result = a / b;
      cout << "A / B = " << result << endl;
      break;
    case 5:
      result = (int) a % (int) b;
      cout << "A % B = " << result << endl;
      break;
    }

    system("sleep 2");
  }
}