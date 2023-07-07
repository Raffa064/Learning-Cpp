#include <functional>
#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
  int chunk_size = 10;
  T *data;
  int size, allocated;

  // Aloca memoria para uma certa quantia de items
  T *allocate(int amount) {
    T *_data = new T[amount];
    return _data;
  }

  // Copia dados para um outro array
  void moveData(T *to) {
    for (int i = 0; i < size; i++) {
      to[i] = data[i];
    }
  }

  // Expande a memoria em 1 chunk
  void expand() {
    allocated += chunk_size;
    T *newData = allocate(allocated);
    moveData(newData);

    delete[] data;
    data = newData;
  }

public:
  // Construtor
  List(int chunk_size = 10) {
    this->chunk_size = chunk_size; // Tamanho da expansão
    allocated = chunk_size;
    data = allocate(allocated);
    size = 0;
  }

  // Adiciona um novo item
  void add(T item) {
    if (size + 1 >= allocated) {
      expand();
    }
    data[size++] = item;
  }

  // Pega um tem
  T get(int index) { return data[index]; }

  // Remove um item
  T remove(int index) {
    T item = data[index];
    for (int i = index; i < size; i++) {
      data[i] = data[i + 1];
    }
    size--;
    return item;
  }

  // Itera sobre a lista
  void forEach(void (*callback)(int i, T item)) {
    for (int i = 0; i < size; i++) {
      callback(i, data[i]);
    }
  }

  ~List() { // Destrutor (limpa memoria)
    cout << "Destructed" << endl;
    if (data != NULL) {
      delete[] data;
    }
  }
};

void print(int i, string item) { cout << item << ", "; }

void myList() {
  List<string> list = List<string>(5);

  for (int i = 1; i <= 10; i++) {
    list.add("Item #" + to_string(i));
  }

  cout << "list[0] = " << list.get(0) << endl;

  list.forEach(&print);
  cout << endl;

  cout << endl << "Remove: " << list.remove(1) << endl << endl;

  list.forEach(&print);
  cout << endl;
}