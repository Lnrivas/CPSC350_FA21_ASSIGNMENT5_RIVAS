/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the implementation .cpp file for the Student class.
*/
#include "Student.h"

Student::Student() {
  timeNeededAtWindow = 0;
  waitTime = 0;
  timeEnteringLine = 0;
  timeAtWindow = 0;
}

Student::Student(int t, int entry) {
  timeNeededAtWindow = t;
  waitTime = 0;
  timeEnteringLine = entry;
  timeAtWindow = 0;
}

Student::~Student() {

}

int Student::getTimeNeededAtWindow() {
  return timeNeededAtWindow;
}

void Student::setTimeNeededAtWindow(int t) {
  timeNeededAtWindow = t;
}

int Student::getWaitTime() {
  return waitTime;
}

void Student::setWaitTime(int time) {
  waitTime = time;
}

int Student::getTimeEnteringLine() {
  return timeEnteringLine;
}

int Student::getTimeAtWindow() {
  return timeAtWindow;
}

void Student::updateTimeAtWindow() {
  ++timeAtWindow;
}
