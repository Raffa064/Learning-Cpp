#include <iostream>

using namespace std;

int sum(int a, int b) { return a + b; }

int sum(int a, int b, int c) {
  return sum(sum(a, b), c);
}

void methodOverload() {
    cout << "SUM(2, 3) = " << sum(2, 3) << endl;
    cout << "SUM(2, 3, 4) = " << sum(2, 3, 4) << endl;
}