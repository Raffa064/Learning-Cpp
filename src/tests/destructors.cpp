#include <iostream>

using namespace std;

/*
  Os destrutores são necessários para liberar a memória alocada por
  ponteiros declarados no escopo da classe já que eles ficam fora da
  estrutura da objeto em memoria e não são liberados pelo delete
  diretamente.
*/

class OtherClass;

class Class {
public:
  OtherClass *pointer;
};

class OtherClass {
public:
  int number;
};

class ClassWithDestructor {
public:
  OtherClass *pointer;

  ~ClassWithDestructor() {
    delete pointer;
    cout << "Destructor has been called!" << endl;
  }
};

void destructors() {
  // Exemplo sem destrutor (pointer não é liberado)
  Class *obj = new Class();
  obj->pointer = new OtherClass();
  OtherClass *pointer = obj->pointer;
  pointer->number = 64;

  delete obj;

  cout << "Pointer aren't cleaned up, also the number is: " << pointer->number
       << endl;

  // Exemplo com destrutor (pointer é liberado)
  ClassWithDestructor *obj2 = new ClassWithDestructor();
  obj2->pointer = new OtherClass();
  OtherClass *pointer2 = obj2->pointer;
  pointer2->number = 64;

  delete obj2;

  cout << "Pointer2 are cleaned up, also the number is: " << pointer2->number
       << endl;

  // Exemplo com destrutor na stack (somente pointer é liberado)
  ClassWithDestructor obj3 = ClassWithDestructor();
  obj3.pointer = new OtherClass();
  OtherClass *pointer3 = obj3.pointer;
  pointer3->number = 64;

  obj3.~ClassWithDestructor(); // obj3 so será apagado ao fim do escopo

  cout << "Pointer3 are cleaned up, also the number is: " << pointer2->number
       << endl;
}