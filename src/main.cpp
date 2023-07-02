/*
  include com aspas => path real/relativo
  include com setas relacionais => biblioteca nativa
*/

#include "./tests/arithmetic.cpp"
#include "./tests/arrays.cpp"
#include "./tests/classes.cpp"
#include "./tests/conditionals.cpp"
#include "./tests/hello-world.cpp"
#include "./tests/incremental.cpp"
#include "./tests/input.cpp"
#include "./tests/loops.cpp"
#include "./tests/function-overload.cpp"
#include "./tests/minigame.cpp"
#include "./tests/pascal-pyramid.cpp"
#include "./tests/pointers.cpp"
#include "./tests/prototype.cpp"
#include "./tests/structs.cpp"
#include "./tests/switches.cpp"
#include "./tests/templates.cpp"
#include "./tests/variables.cpp"

using namespace std;

int main(int argc, char **argv) {
  system("clear");

  // Remova o comentário de um teste para executar:
  // helloWorld();
  // variables();
  // conditionals();
  // input();
  // loops();
  arrays();
  // pointers();
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

  return 0;
}