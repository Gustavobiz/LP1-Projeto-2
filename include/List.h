#ifndef LIST_H
#define LIST_H

#include "./Node.h"
#include <iostream>
#include <ostream>

using namespace std;

template <typename T>

class List {
private:
  Node<T> *head; /*!< Esta instância da classe Node aponta para o primeiro Nó da
                    lista encadeada.*/
  Node<T> *tail; /*!< Esta instância da classe Node aponta para o último Nó da
                    lista encadeada.*/

public:
  int length = 0; /*!< Esta variável armazena o tamanho da lista encadeada.*/
  /**
   * @brief O construtor List sem argumento seta as variáveis ponteiro head e
   * tail como nulas. Isso assegura que a lista encadeada gerada a partir de
   * objetos List iniciem sempre vazias, ou seja, com o primeiro nó apontando
   * para o nullptr
   */
  List() {
    head = nullptr;
    tail = nullptr;
  }

  /**
   * @brief O destrutor List desaloca cada instância do objeto Node da lista
   * encadeada.
   */
  // ~List() {
  //   Node<T> *temp;

  //   while (head != nullptr) {
  //     temp = head;
  //     head = head->getNext();
  //     delete temp;
  //   }
  // }

  void clear() {
    while(length > 0) {
      remove(length);
    }
  }

  Node<T> *getTail() { return tail; }

  Node<T> *getHead() { return head; }

  int getLength() { return length; }

  /**
   * @brief Esta função verifica se a lista encadeada está vazia.
   * @return Retorna um boolenao, isto é, 1 caso a lista esteja vazia, ou 0 caso
   * contrário.
   */
  bool isEmpty() { return (head == nullptr); }

  /**
   * @brief Esta função verifica se a lista encadeada está cheia.
   * @return Retorna um booleano, isto é, 1 caso a lista esteja cheia, ou 0 caso
   * contrário.
   */
  bool isFull() {
    try {
      Node<T> *newNode = new Node<T>;
      delete newNode;
      return false;
    } catch (bad_alloc exception) {
      return true;
    }
  }

  /**
   * @brief Esta função adiciona um novo elemento à lista encadeada.
   * @param item Uma variável do tipo template que armazena o valor a ser
   * inserido à lista.
   */
  void push(T item) {
    if (isFull()) {
      cout << "Não foi possível inserir o elemento, pois a lista esta cheia."
           << endl;
    } else {
      Node<T> *newNode = new Node<T>;
      newNode->setValue(item);
      newNode->setNext(nullptr);

      if (head == nullptr) {
        head = newNode;
      } else {
        tail->setNext(newNode);
      }

      tail = newNode;
      length++;
    }
  }

  void unshift(List<T> &list) {
    if (head == nullptr) {
      head = list.getHead();
    } else {
      tail->setNext(list.getHead());
    }

    tail = list.getTail();

    length += list.length;
  }

  /**
   * @brief Esta função remove um novo elemento da lista encadeada.
   */
  void pop() {
    if (isEmpty()) {
      cout << "Não foi possível remover um elemento, pois a lista esta vazia.\n"
           << endl;
    } else {
      Node<T> *temp = head;
      head = head->next;

      if (head == nullptr) {
        tail = nullptr;
      }

      delete temp;
      length--;
    }
  }

  /**
   * @brief Esta função procura por um elemento da lista encadeada a partir de
   * um index (int) específico.
   * @params index Um inteiro que será usado como index do elemento procurado.
   * @return Um ponteiro que aponta para uma instância da classe Node.
   */
  Node<T> *get(int index) {
    int i = index;
    Node<T> *temp = head;

    if (i < length) {
      while (i > 0) {
        temp = temp->getNext();
        i--;
      }
    }

    return temp;
  }

  int getForIndex(T element) {
    int i = 0;

    Node<T> *temp = head;
    while(temp != nullptr && temp->getValue() != element) {
      temp = temp->getNext();
      i += 1;
    }

    if (temp == nullptr) {
      return -1;
    }

    return i;
  }

  /**
   * @brief Esta função remove um elemento da lista encadeada a partir de um index (int) específico.
   * @params i Um inteiro que será usado como index do elemento a ser removido.
   */
  void remove(int i) {
    if (!isEmpty()) {
      Node<T> *temp = get(i);

      if (i == length - 1 and length > 1) {
        Node<T> *previusNode = get(i - 1);
        previusNode->setNext(nullptr);
        tail = previusNode;
      } else if (i > 0) {
        Node<T> *previusNode = get(i - 1);
        previusNode->setNext(temp->getNext());
      } else {
        head = temp->getNext();
      }

      length--;

      delete temp;
    } else {
      cout << "Não foi possível remover o elemento, pois a lista está vazia." << endl;
    }
  }

  void removeList (List<T> &l) {
    for(int i=0; i<l.length; i++) {
      int index = 0;

      Node<T> *temp = head;
      while(temp != nullptr && temp->getValue() != l.get(i)->getValue()) {
        temp = temp->getNext();
        index += 1;
      }
  
      if (temp == nullptr) {
        continue;
      }

      remove(index);
    }
  }

  List<T> copy(List<T> &l) {
    List<T> list;

    for(int i=0; i<l.length; i++) {
      list.push(l.get(i)->getValue());
    }

    return list;
  }

  List<T> operator + (List<T> l) {
    List<T> list;

    Node<T>* temp = head; 
    
    while(temp != nullptr) {
      list.push(temp->getValue());
      temp = temp->getNext();
    }

    list.unshift(l);

    return list;
  }

  void operator >> (Node<T>& item) {
    Node<T>* temp = head;

    while(temp != nullptr) {
      item.setValue(temp->getValue());
      item.setNext(nullptr);
      temp = temp->getNext();
    }
  }

  void operator << (T& item) {

    this->push(item);
  }

  /**
   * @brief Esta função imprime todos os elementos da lista encadeada de maneira
   * recursiva.
   * @params i Um inteiro que será usado como index do elemento a ser impresso.
   */
  void print(int i) {
    if (length == 0) {
      cout << "A lista está vazia." << endl;
    } else {
      if (i == length) {
        return;
      } else {
        cout << get(i)->getValue() << endl;
        print(i + 1);
      }
    }
  }
};

#endif