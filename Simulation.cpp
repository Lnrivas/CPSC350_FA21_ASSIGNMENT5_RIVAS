/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the implementation .cpp file for the Simulation class.
*/
#include "Simulation.h"

Simulation::Simulation() {
  windows = 0;
  entryTime = 0;
  students = 0;
  timeNeededAtWindow = 0;
}

Simulation::~Simulation() {

}

void Simulation::readFile(string fileName, GenQueue<Student*>* line) { //reads input file and sets up queue
  fstream fileStream;
  fileStream.open(fileName, ios::in); // opens inputFile in read mode
  if (fileStream.fail()) { // ensures file was opened incorrectly
    throw runtime_error("Input file not opened!");
	}
  fileStream >> windows;
  while (true) { // loops through entire file, int by int, until the end is reached 
    fileStream >> entryTime; //read time passed
    fileStream >> students; //read num of Students
    for (int i = 0; i < students; ++i) {
      fileStream >> timeNeededAtWindow; //read time needed at window for each student that just came
      line->insert(new Student(timeNeededAtWindow, entryTime)); //putting students into queue
    }
		if (fileStream.eof()) { //breaks out of loop once the entire file has been read.
      break;
    }
	}
	fileStream.close();
}

int Simulation::getWindows() {
  return windows;
}
