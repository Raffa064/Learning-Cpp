#include <iostream>

using namespace std;

/*
  Memoria Global (ou estática)
  Memoria responsável por armazenar valores globais,
  que continuam na memoria durante todo o programa:

  int staticMemory = 64;

  void example(int stackMemory) {
    int *heapMemory = new int;

    cout << "Endereço da variável na static memory: " << &staticMemory << endl;
    cout << "Endereço da variável na stack memory: " << &stackMemory << endl;
    cout << "Endereço da variável na heap memory: " << &heapMemory << endl;

    delete heapMemory;
  }

  Memoria Stack
  Usada para armazenar variáveis e parâmetros,
  a memoria stack é alocada automaticamente.

  ex:

  void sum(int a, int b) {
    return a + b;
  }

  essa função possui 2 variáveis int, portanto, vai ter
  pelo menos 8 bytes alocados na memoria stack para comportar
  esses valores.

  Memoria HEAP (ou dinâmica)
  Memoria dinâmica, é usada e gerenciada pelo
  o programador, a partir das keywords new e delete.

  ex:

  int sum(int a, int b) {
    int *pointer = new int;
    *pointer = a + b; // seta o valor armazenado na heap como a + b

    return *pointer;  // retorna valor armazenado na heap
  }

  vai ser alocado 4 byte na memoria para armazenar o valor
  da variável sum, e esse valor vai ficar la até o programa
  acabar, pois ele não foi desalocado, para resolver isso:

  int* sum(int a, int b) {
    int *pointer = new int;
    *pointer = a + b; // seta o valor armazenado na heap como a + b

    return pointer;  // retorna o ponteiro ao invés do valor
  }

  int* pointer = sum(5, 3);
  delete pointer;  // desaloca a o valor armazenado na heap

*/

void pointers() {
  // O ponteiro é usado para apontar para endereços de memoria

  int *x = new int; // Ponteiro para um novo inteiro que esta na heap
  delete x;         // desalocar x da heap

  int y = 64;
  int *z = &y; // ponteiro para referência de variável

  int *pointer; // ponteiro nulo

  int n = 32;
  int &ref = n; // Referencia de n (ref é referência do mesmo valor na memoria)

  /*
    uma referência NÃO pode ser declarada como nula, nem apontar para literais,
    porém, se ela referenciar um valor da stack que foi desempilhado ou valor
    desalocado da heap, ela pode causar problemas!
  */

  string *str = new string;
  *str = "Hello world";
  string &strRef = *str;

  cout << "String from HEAP: " << *str << endl;
  cout << "String address on HEAP: " << str << endl;
  cout << "String reference: " << strRef << endl;

  // Ponteiro podem apontar arrays (um item dele em especifico)
  int array[] = {1, 2, 3, 4};
  int *p = array; // *p == array[0]

  /*
    um ponteiro int* não aponta diretamente para o array,
    mais sim pro primeiro item

    Além disso ponteiro pode ser usado com operações de + e -
    para se mover na memoria. ele funciona como um endereço,
    ou numero inteiro, então da para fazer isso por exemplo:

    ponteiro++
    --ponteiro
    ponteiro += 10

    Num ponteiro, o valor da adição e subtração de endereços é
    equivalente ao número da adição/subtração multiplicado pela quantidade
    de bytes do seu tipo:

    intPointer += 2    // Pula 8 bytes (2 * 4)
    charPointer += 2   // Pula 2 bytes (1 * 2)
    objectPointer += 2 // Pula 2n bytes (Depende do tamanho do objeto em bytes)

    OBS: os ponteiro pode usar [] como se fosse array
  */

  int secondItem = *(p + 1); // mesmo que array[0+1], ou array[1]
  int otherWay = p[1];       // também é o mesmo que array[1]

  int length = sizeof(array) / sizeof(int);
  for (int i = 0; i < length; i++) {
    cout << *(p + i) << ", "; // p+i pula 4*i bytes, ja q int tem 4 bytes
  }

  cout << endl;
}

/*
  char*
  pode ser um ponteiro para uma array de caracteres (array de char)

  char**
  pode ser um ponteiro para um array de ponteiros para vários
  arrays de caracteres (array de string)
*/