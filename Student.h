/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the header .h file for the Student class
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
public:
  Student(); //default constructor
  Student(int t, int entry); //overloaded constructor
  ~Student(); //default destructor
  int getTimeNeededAtWindow(); //returns timeNeededAtWindow
  void setTimeNeededAtWindow(int t); //sets timeNeededAtWindow
  int getWaitTime(); //returns waitTime
  void setWaitTime(int time); //sets waitTime
  int getTimeEnteringLine(); //returns timeEnteringLine
  int getTimeAtWindow(); //returns timeAtWindow
  void updateTimeAtWindow(); //updates timeAtWindow by 1

private:
  int timeNeededAtWindow;
  int waitTime;
  int timeEnteringLine;
  int timeAtWindow;
};

#endif
