#include <iostream>

using namespace std;

class Car {
public:
  string model;
  string mark;
  int year;
  string licensePlate;

  Car(string _model, string _mark, int _year, string _licensePlate) {
    model = _model;
    mark = _mark;
    year = _year;
    licensePlate = _licensePlate;
  }
};

class Fusca : public Car {
public:
  Fusca(string _licensePlate)
      : Car("Fusca", "Volkswagen", 1959, _licensePlate) {}
};

class Vectra : public Car {
public:
  Vectra(string _licensePlate)
      : Car("Vectra", "Chevrolet", 1996, _licensePlate) {}
};

void printCarData(Car &);

void heritage() {
  Fusca fusca = Fusca("ABC-1234");
  Vectra vectra = Vectra("CAB-2345");
  
  printCarData(fusca);
  printCarData(vectra);
}

void printCarData(Car &car) {
  cout << "Model: " << car.model << endl;
  cout << "Mark: " << car.mark << endl;
  cout << "Year: " << car.year << endl;
  cout << "Lis. Plate: " << car.licensePlate << endl;
}