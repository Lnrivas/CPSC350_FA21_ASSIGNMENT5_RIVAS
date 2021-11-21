/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This .h file is a list interface and a template class for a list based off of my doubly linked list
*/
#ifndef MYLIST_H
#define MYLIST_H

#include "GenLinkedList.h"

using namespace std;

template<typename T>
class ListInterface{
public:
  ListInterface(){} //default constructor
  virtual ~ListInterface(){} //default destructor
  virtual void Append(T data) = 0; // Append(list, x)	Inserts x at end of list	Append(list, 44), list: 99, 77, 44
  virtual void Prepend(T data) = 0; // Prepend(list, x)	Inserts x at start of list	Prepend(list, 44), list: 44, 99, 77
  virtual T Remove() = 0; // Remove(list, x)	Removes x	Remove(list, 77), list: 99
  virtual T Search(T data) const = 0; // Search(list, x)	Returns item if found, else returns null	Search(list, 99), returns item 99   Search(list, 22), returns null
  virtual void Print() const = 0; // Print(list)	Prints list's items in order	Print(list) outputs: 99, 77
  virtual bool IsEmpty() const = 0; // IsEmpty(list)	Returns true if list has no items	For list 99, 77, IsEmpty(list) returns false
  virtual int GetLength() const = 0; // GetLength(list)	Returns the number of items in the list	GetLength(list) returns 2
};

template<typename T>
class MyList : public ListInterface<T> {
public:
  MyList();
  ~MyList();
  virtual void Append(T data);
  virtual void Prepend(T data);
  virtual T Remove();
  virtual T Search(T data) const;
  virtual void Print() const;
  virtual bool IsEmpty() const;
  virtual int GetLength() const;
  virtual T getFront() const;
private:
  DoublyLinkedList<T> *myLinkedList;
};

template<typename T>
MyList<T>::MyList(){ // initialize doubly linked list
  myLinkedList = new DoublyLinkedList<T>();
}

template<typename T>
MyList<T>::~MyList() {
  delete myLinkedList;
}

template<typename T>
void MyList<T>::Append(T data) {
  myLinkedList->insertBack(data);
}

template<typename T>
void MyList<T>::Prepend(T data) {
  myLinkedList->insertFront(data);
}

template<typename T>
T MyList<T>::Remove() {
  return myLinkedList->removeFront();
}

template<typename T>
T MyList<T>::Search(T data) const {
  myLinkedList->find(data);
}

template<typename T>
void MyList<T>::Print() const {
  myLinkedList->printList(false);
}

template<typename T>
bool MyList<T>::IsEmpty() const {
  myLinkedList->isEmpty();
}

template<typename T>
int MyList<T>::GetLength() const {
  myLinkedList->getSize();
}

template<typename T>
T MyList<T>::getFront() const {
  return myLinkedList->getFrontData();
}

#endif
