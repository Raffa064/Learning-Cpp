/*
  include com aspas => path real/relativo
  include com setas relacionais => biblioteca nativa
*/

#include "./tests/arithmetic.cpp"
#include "./tests/arrays.cpp"
#include "./tests/classes.cpp"
#include "./tests/conditionals.cpp"
#include "./tests/function-overload.cpp"
#include "./tests/functions.cpp"
#include "./tests/hello-world.cpp"
#include "./tests/incremental.cpp"
#include "./tests/input.cpp"
#include "./tests/loops.cpp"
#include "./tests/memory.cpp"
#include "./tests/minigame.cpp"
#include "./tests/my-list.cpp"
#include "./tests/pascal-pyramid.cpp"
#include "./tests/pointers.cpp"
#include "./tests/prototype.cpp"
#include "./tests/structs.cpp"
#include "./tests/switches.cpp"
#include "./tests/templates.cpp"
#include "./tests/valid-cpf.cpp"
#include "./tests/variables.cpp"
#include "./tests/fatorial-function.cpp"

using namespace std;

/*
  Na função main o argc é importante pq o argv usa ponteiro
  ao invés de array, e não da para fazer conversão direta de
  ponteiro para array, embora o contrario funcione.
*/

int main(int argc, char **argv) {
  system("clear");

  // Remova o comentário de um teste para executar:
  // helloWorld();
  // variables();
  // conditionals();
  // input();
  // loops();
  // arrays();
  // pointers();
  // memory(64);
  // functionOverload();
  // structs();
  // classes();
  // switches();
  // arithmetic();
  // pascalPyramid();
  // minigame();
  // incremental();
  // prototype();
  // templates();
  // functions();
  // validCPF();
  // myList();
  fatorial();
  return 0;
}