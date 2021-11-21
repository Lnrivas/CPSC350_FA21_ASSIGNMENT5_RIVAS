/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the header .h file for the Simulation class
*/
#ifndef SIMULATION_H
#define SIMULATION_H
#include <fstream>
#include "GenQueue.h"
#include "Student.h"
using namespace std;

class Simulation {
public:
  Simulation(); //default constructor
  ~Simulation(); //default destructor
  void readFile(string fileName, GenQueue<Student*>* line); //reads the input file and sets up the queue
  int getWindows(); // returns the total number of windows

private:
  int windows;
  int entryTime;
  int students;
  int timeNeededAtWindow;

};

#endif
