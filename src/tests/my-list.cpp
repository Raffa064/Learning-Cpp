#include <functional>
#include <iostream>
#include <string>

using namespace std;

template <class T> class List {
  int chunk_size = 10;
  T *data;
  int size, allocated;
  bool autoFit;

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
  List(int chunk_size = 10, bool autoFit = true) {
    this->chunk_size = chunk_size; // Tamanho da expansão
    this->autoFit = autoFit;       // Flag para regular tamanho do buffer
    allocated = chunk_size;
    data = allocate(allocated);
    size = 0;
  }

  // Pegar quantia maxima de memória alocada
  int getBufferSize() { return allocated; }

  // Regula tamanho da lista de acordo com a quantia de items
  void fit() {
    int chunks = max(1, getBufferSize() / chunk_size);
    int needled_chunks = max(1, getSize() / chunk_size);

    if (chunks - needled_chunks > 0) {
      allocated = needled_chunks * chunk_size;
      T *newData = allocate(allocated);
      moveData(newData);
      delete[] data;
      data = newData;
    }
  }

  // Setar ajuste automatico
  void setAutoFit(bool autoFit) { this->autoFit = autoFit; }

  // Pegar ajuste automatico
  bool isAutoFit() { return autoFit; }

  // Pegar quantia de itens armazenados
  int getSize() { return size; }

  // Adiciona um novo item
  void add(T item) {
    if (size + 1 >= allocated) {
      expand();
    }
    data[size++] = item;
  }

  // Adiciona em um index específico
  void add(int index, T item) {
    if (size + 1 >= allocated) {
      expand();
    }

    size++;
    T last = data[index];
    data[index] = item;

    for (int i = index + 1; i < size; i++) {
      T current = data[i];
      data[i] = last;
      last = current;
    }
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

    if (autoFit)
      fit();
    return item;
  }

  // Itera sobre a lista
  void forEach(void (*callback)(int, int, T)) {
    for (int i = 0; i < size; i++) {
      callback(i, size, data[i]);
    }
  }

  ~List() { // Destrutor (limpa memoria)
    if (data != NULL) {
      delete[] data;
    }
  }
};

// void print(int, int, int);

void print(int index, int size, int item) {
  cout << item;
  if (index + 1 == size) {
    cout << endl;
  } else {
    cout << ", ";
  }
}

void myList() {
  List<int> numbers = List<int>();

  // Adicionar itens
  numbers.add(16);
  numbers.add(32);
  numbers.add(64);
  numbers.add(128);

  // Remover itens
  numbers.remove(1); // 32
  numbers.remove(2); // 128

  // Inserir items em index específicos
  numbers.add(0, 20); // insere 20 no primeiro indice
  numbers.add(1, 30); // insere 20 no segundo indice

  // Printar na tela
  numbers.forEach(&print); // 20, 30, 16, 64

  cout << "List size: " << numbers.getSize() << endl;
  cout << "List buffer size: " << numbers.getBufferSize() << endl;
}
