#include <iostream>

using namespace std;

void input() {
  cout << "Enter your name: ";
  string input;
  cin >> input; //Console-In
  cout << endl << "Hello " + input << "!" << endl;
}