#include <iostream>

using namespace std;

void arrays() {
  int array[5] = {0, 0, 0, 0, 0};

  cout << "Acessando index inexistente do array: ";
  for (int i = 0; i < 5; i++) {
    // Index fora do range: sem exception, acessa memória indevida
    cout << array[i + 1] << ", ";
  }

  cout << endl;

  char string[8] = "Exemplo";
  // A string tem 7 letras, mas o array tem 8 por causa de
  // um detalhe técnico de que as string terminam em \0

  int matrix[5][5]; // Matrix YX

  // o sizeof retorna o tamanho em bytes de um valor
  // então o quantidade de items num array é
  // o tamanho do array, dividido pelo tamanho dos items
  int height = sizeof(matrix) / sizeof(matrix[0]);
  int width = sizeof(matrix[0]) / sizeof(matrix[0][0]);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      matrix[i][j] = rand() % 10;
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  // Sem o tamanho definido ele pega o tamanho automaticamente
  // Porem, so funciona com um array literal passado diretamente
  char str[] = "Hello World";
  int other[] = {345, 435, 435};
}
