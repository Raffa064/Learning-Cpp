#include <iostream>

using namespace std;

/*
  As funções template, são basicamente funções que usam generics

*/

template <class ANY> bool isInteger(ANY);

void templates() {
  isInteger('h');
  isInteger(34.2f);
  isInteger(44.24);
  isInteger(34);
  isInteger(true);
  isInteger("Text value");
}

template <class ANY> bool isInteger(ANY value) {
  bool is = typeid(value) == typeid(int);

  if (is)
    cout << "\"" << value << "\" is a integer value" << endl;
  else
    cout << "\"" << value << "\" isn't a integer value" << endl;

  return is;
}