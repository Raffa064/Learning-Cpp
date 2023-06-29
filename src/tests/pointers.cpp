#include <iostream>

using namespace std;

void pointers() {
  // pointer&    =   referencia
  // reference*  =   ponteiro

  int x = 64;
  int *pointer = &x;         // Ponteiro da referencia
  int &reference = *pointer; // Referencia do ponteiro

  cout << "X = " << x << endl;
  cout << "POINTER = " << pointer << endl;
  cout << "REFERENCE = " << reference << endl;
}