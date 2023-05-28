#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
  private:
    T value; /*!< Esta variável do tipo template armazena o valor do Nó */
    Node* next; /*!< Este ponteiro aponta para o próximo Nó da lista encadeada. */

  public:
    
    Node() {}

    ~Node() {}

    T& getValue() {
      return value;
    }

    void setValue(T v) {
      value = v;
    }

    Node* getNext() {
      return next;
    }

    void setNext(Node* n) {
      next = n;
    }

};

#endif