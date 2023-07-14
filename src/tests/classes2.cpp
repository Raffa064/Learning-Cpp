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

  void printData(); // Protótipo do método printData 
};

// Implementação do método printData
void Person::printData() {
  cout << "Nome: " << name << endl;
  cout << "Country: " << country << endl;
  cout << "Age: " << age << endl;
  cout << "Height: " << height << endl;
}

void classes2() {
  Person rafael = Person("Rafael", "Brazil", 16, 1.7f);
  rafael.printData();
}