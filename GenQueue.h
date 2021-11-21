/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This .h file is a template class for a Queue based off of a doubly linked list
*/
#ifndef GENQUEUE_H
#define GENQUEUE_H
#include "MyList.h"

using namespace std;

template <class T>
class GenQueue {
public:
  GenQueue(); //default constructor
  ~GenQueue();
  //core functions
  void insert(T data); // aka enqueue()
  T remove(); //aka dequeue()
  //aux functions
  T peek();
  unsigned int getSize();
  bool isEmpty();
  void printList();
private:
  int front;
  int rear;
  unsigned int numElements;
  MyList<T> *myList;
};

//implementation
template <class T>
GenQueue<T>::GenQueue() {
  myList = new MyList<T>();
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue() {
  delete myList;
}

template <class T>
void GenQueue<T>::insert(T data) {
  myList->Append(data);
  ++rear;
  ++numElements;
}

template <class T>
T GenQueue<T>::remove() {
  if(isEmpty()) {
    throw runtime_error("queue is empty!");
  }
  --numElements;
  return myList->Remove();
}

template <class T>
T GenQueue<T>::peek() {
  if (isEmpty()) {
    throw runtime_error("queue is empty");
  }
  return myList->getFront();
}

template <class T>
bool GenQueue<T>::isEmpty() {
  return (numElements == 0);
}

template <class T>
unsigned int GenQueue<T>::getSize() {
  return numElements;
}

template <class T>
void GenQueue<T>::printList() {
  myList->Print();
}


#endif
