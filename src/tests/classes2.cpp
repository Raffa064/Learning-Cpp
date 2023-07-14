#include <iostream>

using namespace std;

/*
  Esse código foi feito para testar prototipagem de métodos
*/

class Person {
  string name, country;
  int age;
  float height;

public:
  Person(string name, string country, int age, float height) {
    this->name = name;
    this->country = country;
    this->age = age;
    this->height = height;
  }

  void printData(); // Método protótipo
};

void Person::printData() {
  cout << "Nome: " << this->name << endl;
  cout << "Country: " << this->country << endl;
  cout << "Age: " << this->age << endl;
  cout << "Height: " << this->height << endl;
}

void classes2() {
  Person rafael = Person("Rafael", "Brazil", 16, 1.7f);
  rafael.printData();
}