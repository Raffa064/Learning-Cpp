#include <iostream>
#include <string>
#include <thread>

using namespace std; // equivale ao import do java

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

class Fruit {
  // Diferença do struct: private é o modificador padrão
  float sweetness;
  float acidity;

protected:
  Fruit(float sweetness, float acidity) {
    this->sweetness = sweetness;
    this->acidity = acidity;
  }

public:
  void setSweetness(float sweetness) { this->sweetness = sweetness; }

  float getSweetness() { return sweetness; }

  void setAcidity(float acidity) { this->acidity = acidity; }

  float getAcidity() { return acidity; }

  bool isSweet() { return sweetness > acidity; }

  bool isAcid() { return acidity > sweetness; }

  // Somente métodos virtuais podem ser sobrescritos
  virtual string getName() { return "Fruit"; }
};

class Apple : Fruit {
public:
  Apple() : Fruit(0.9, 0.1) {} // Equivalente de super(...)

  // As classes deixam os membros da classe pai privados

  // Para expor membros da classe pai:
  using Fruit::getAcidity;
  using Fruit::getSweetness;
  using Fruit::isAcid;
  using Fruit::isSweet;
  using Fruit::setAcidity;
  using Fruit::setSweetness;

  string getName() override { return "Apple"; }
};

class Lemon : Fruit {
public:
  Lemon() : Fruit(0.0, 0.99) {}

  using Fruit::getAcidity;
  using Fruit::getSweetness;
  using Fruit::isAcid;
  using Fruit::isSweet;
  using Fruit::setAcidity;
  using Fruit::setSweetness;

  string getName() override { return "Lemon"; }
};

void helloWorld() { cout << "Hello world" << endl; }

void variables() {
  // i é um numero aleatório pq acredite ou não...
  // variáveis iniciam com o valor q tava na memoria na
  // qual ela for alocada kkk

  int i;
  cout << i << endl;

  unsigned int j = -4; // Unsigned não permite negativos, então isso da vira
                       // total o numero inteiro máximo menos 4
  cout << j << endl;

  char character = 'R';
  char string[7] = "Rafael"; // o index é 7 e a string tem 6 dígitos, pq ela
                             // obrigatoriamente termina em \0

  std::string str = "Rafael é foda";
  str += " parte concatenada";
  cout << str << endl;

  // Essa é a notação de array do c++
  bool teste[2] = {true, false};
}

void conditionals() {
  // Nada diferente por aqui

  int i = 0;

  if (i >= 0) {
    cout << "i is greater than 0" << endl;
  } else if (i == 0) {
    cout << "i is equals then 0" << endl;
  } else {
    cout << "i is less than 0" << endl;
  }

  bool ex = 30 < 40 || i == 40;
}

void input() {
  cout << "Enter your name: ";
  std::string input; // pq string precisa de std msm com "using namespace"?
  cin >> input;
  cout << endl << "Hello " + input << endl;
}

void loops() {
  // Nothing new here.
  int i = 0;
  while (i < 10) {
    cout << "WHILE: " << i << endl;
    i++;
  }

  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      cout << "number 5 skipped" << endl;
      continue;
    }

    if (i == 8) {
      cout << "number 8 breaks the loop" << endl;
      break;
    }

    cout << "FOR: " << i << endl;
  }
}

void arrays() {
  int array[5] = {0, 0, 0, 0, 0};

  cout << "Acessando index inexistente: ";
  for (int i = 0; i < 5; i++) {
    // Index fora do range: sem exception, acessa memória indevida
    cout << array[i + 1] << ", ";
  }

  cout << endl;
}

void pointers() {
  // pointer&    =   referencia
  // reference*  =   ponteiro

  int x = 64;
  int *pointer = &x;         // Ponteiro da referencia
  int &reference = *pointer; // Referencia do ponteiro
}

int sum(int a, int b) { return a + b; }

int sum(int a, int b, int c) {
  // C++ aceita sobrecarga de  métodos
  return sum(sum(a, b), c);
}

void sumTest() {
  int a = 64;
  int b = 32;

  cout << "A + B = " << sum(a, b) << endl;
}

void useStruct() {
  // O Human é um struct: ele não gera referencia, e o construtor não usa new
  Human test = Human(16, "Rafael", "Marcos", "Brazil");
  cout << test.getFullName() << " is a Human of " << test.age << "th years old!"
       << endl;

  // Declaração direta: da para fazer em classe e em struct
  Human test2(27, "Fulano", "Aleatório"); // Country como default == "Brazil"
  cout << test2.getFullName() << " is a Human of " << test2.age
       << "th years old!" << endl;
}

void useClass() {
  std::string isSweet;

  Apple apple = Apple();
  isSweet = apple.isSweet() ? "sweet" : "acid";
  cout << "Apple is " << isSweet << endl;

  Lemon lemon = Lemon();
  isSweet = lemon.isSweet() ? "sweet" : "acid";
  cout << "Lemon is " << isSweet << endl;
}

void useSwitch() {
  char input;
  bool alreadyChoose;

  do {
    cout << "Digite uma letra de A a D: ";
    cin >> input;

    alreadyChoose = true;

    switch (input) {
      case 'a':
      case 'A':
        cout << "Always" << endl;
        break;
      case 'b':
      case 'B':
        cout << "Bee" << endl;
        break;
      case 'c':
      case 'C':
        cout << "Cow" << endl;
        break;
      case 'd':
      case 'D':
        cout << "Dice" << endl;
        break;
      default: alreadyChoose = false; break;
    }
  } while (!alreadyChoose);

  cout << "Finished: " << input << endl;
}

int main(int argc, char **argv) {
  system("clear");

  //   helloWorld();
  //   variables();
  //   conditionals();
  //   input();
  //   loops();
  //   arrays();
  //   pointers();
  // sumTest();
  // useStruct();
  // useClass();
  useSwitch();

  return 0;
}