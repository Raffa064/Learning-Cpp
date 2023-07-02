#include <iostream>

using namespace std;

// Struct é um "container de dados"
struct Human {
  // Diferença das classes: field são públicos por padrão

  int age;
  string name;
  string secondName;
  string country;

  Human() {
    // Construtor padrão
    age = 0;
    name = "";
    secondName = "";
    country = "none";
  }

  // C++ aceita valor padrão nos parâmetros
  Human(int age, string name, string secondName, string country = "Brazil") {
    // this é um ponteiro, por isso não ta usando notação de ponto
    // value->field é equivalente a (*value).field = x

    this->age = age;
    this->name = name;
    this->secondName = secondName;
    this->country = country;
  }

  string getFullName() { return name + " " + secondName; }
};

// extends do java
struct Rafael : Human {
private:
  bool knowJava = true;
  bool knowCpp = false;

public:
  Rafael() { name = "Rafael"; }
};

/*
  As expressões

  struct <Name> {...};
   ou
  class <Name> {...};

  São lidas instantaneamente como tipo de dados, então da para criar variáveis:

  struct Struct {} exemple;    -->      Struct example;

  class Classe {} exemple2;    -->      Classe example2;

*/

struct Data {
  int a, b;
  string c;
  int d;
} instance0, instance1, instance2;

void structs() {
  // O Human é um struct: ele não gera referencia, e o construtor não usa new
  Human test = Human(16, "Rafael", "Marcos", "Brazil");
  cout << test.getFullName() << " is a Human of " << test.age << " years old!"
       << endl;

  // Declaração direta: da para fazer em classe e em struct
  Human test2(27, "Fulano", "Aleatório"); // Country como default == "Brazil"
  cout << test2.getFullName() << " is a Human of " << test2.age << " years old!"
       << endl;

  // Da para declarar "objeto" com um array de valor
  // o array tem q tar na mesma ordem de declaração
  // isso funciona para classe também, e da bo se tiver
  // algum valor privado na estrutura/classe
  Data teste3 = {1, 1, "Exemplo", 1};
}