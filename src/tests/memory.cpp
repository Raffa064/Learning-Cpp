#include <iostream>

using namespace std;

int staticMemory = 64;

void memory(int stackMemory) {
  int *heapMemory = new int;

  cout << "Endereço da variável na static memory: " << &staticMemory << endl;
  cout << "Endereço da variável na stack memory: " << &stackMemory << endl;
  cout << "Endereço da variável na heap memory: " << &heapMemory << endl;

  delete heapMemory;
}
