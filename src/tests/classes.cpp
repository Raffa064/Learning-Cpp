#include <iostream>

using namespace std;

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

class Apple : public Fruit {
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

class Lemon : public Fruit {
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

void printFruitData(Fruit &fruit) {
  /*
    Se não for passado como referência, o valor de fruit vai ser uma
    copia do valor original, e por ter o tipo Fruit, irá ocorrer
    uma conversão, que causa slicing (corte) de informações de subclasses
    como Apple e Lemon.
  */

  std::string isSweet;
  isSweet = fruit.isSweet() ? "sweet" : "acid";
  cout << fruit.getName() << " is " << isSweet << endl;
}

void classes() {
  Apple apple = Apple();
  Lemon lemon = Lemon();

  // Poliformismo:A função printFruitData aceita qualquer fruta
  printFruitData(apple);
  printFruitData(lemon);
}