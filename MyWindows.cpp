/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the implementation .cpp file for the MyWindow class.
*/
#include "MyWindows.h"

MyWindow::MyWindow() {
  idleTime = 0;
  isEmpty = true;
  newStudent = NULL;
}

MyWindow::~MyWindow() {
  delete newStudent;
}

void MyWindow::updateIdleTime() {
  ++idleTime;
}

int MyWindow::getIdleTime() {
  return idleTime;
}

bool MyWindow::isWindowIdle() {
  return isEmpty;
}

void MyWindow::setWindowBusy() {
  isEmpty = false;
}

Student* MyWindow::getStudent() {
  return newStudent;
}

void MyWindow::setStudent(Student* stud) {
  newStudent = stud;
}

void MyWindow::setWindowIdle() {
  isEmpty = true;
}
