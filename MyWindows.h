/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the header .h file for the MyWindow class
*/
#ifndef MYWINDOWS_H
#define MYWINDOWS_H
#include "Student.h"
using namespace std;

class MyWindow {
public:
  MyWindow(); //default constructor
  ~MyWindow(); //default destructor
  void updateIdleTime(); //increases idle time by one
  int getIdleTime(); // returns idle time
  bool isWindowIdle(); //returns if window is idle
  void setWindowBusy(); //sets window to busy
  Student* getStudent(); //returns newStudent
  void setStudent(Student* s); //sets newStudent (putting a student into the window)
  void setWindowIdle(); //sets window to idle

private:
  int idleTime;
  bool isEmpty;
  Student* newStudent;
};

#endif
