#include <cstddef>
#include <cstdint>
#include <iostream>

using namespace std;

const string VALID = "\033[32mValid\033[37m";
const string INVALID = "\033[31mInvalid\033[37m";

int *sanitize(string);
bool checkSum(int sum);

void validCPF() {
  cout << "Digite um cpf: " << endl;
  string input;
  cin >> input;

  int *cpfNumbers = sanitize(input);

  if (cpfNumbers != NULL) {
    int sum = 0;
    for (int i = 0; i < 11; i++) {
      sum += cpfNumbers[i];
    }
    string isValid = checkSum(sum) ? VALID : INVALID;
    cout << "SUM: " << sum << " -> " << isValid << endl;
    delete[] cpfNumbers;
  } else {
    cout << "\033[31mERROR:\033[36m Invalid number count\033[37m" << endl;
  }
}

int *sanitize(string cpf) {
  int *numbers = new int[11]; // 123.456.789-11

  int index = 0;
  for (int i = 0; i < cpf.length(); i++) {
    int value = cpf.at(i) - '0'; // Converte em inteiro
    if (value >= 0 && value <= 9) {
      numbers[index++] = value;
    }
  }

  if (index != 11) {
    delete[] numbers;
    return NULL;
  }

  return numbers;
}

bool checkSum(int sum) {
  int u = sum % 10;
  int d = (sum / 10) % 10;

  return sum < 100 && u == d;
}