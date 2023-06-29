#include <cstdlib>
#include <iostream>

using namespace std;

/*

OPERADORES BOOLIANOS:

!   NÃO
==  IGUAL
!=  DIFERENTE
<   MENOR
>   MAIOR
<=  MENOR OU IGUAL
>=  MAIOR OU IGUAL
&&  E
||  OU

*/

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

  bool boolExp = 30 < 40 || i == 40; //Expressão booliana (0 ou 1)
  string resultStr = (boolExp ? "true" : "false");
  cout << "(ex = 30 < 40 || i == 40) is equals to " << resultStr << endl;
}