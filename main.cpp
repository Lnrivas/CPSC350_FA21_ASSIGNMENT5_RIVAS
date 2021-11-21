/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the main file, where our main method lives. An input file from the command line argument is read and used as
 * the info to simulate a university's registrar's office. The stats are calculated and printed to standard out.
*/
#include "MyWindows.h"
#include "Simulation.h"
#include "Stats.h"

int main(int argc, char** argv) {
  if (argc != 2) { //ensures command line has one argument for running the program and one argument to be the input file name
    throw runtime_error("Must enter name of input file as a command line argument!");
  }
  GenQueue<Student*> *line = new GenQueue<Student*>();
  Simulation *sim = new Simulation();
  Stats *stats = new Stats();
  int clock = 0;
  sim->readFile(argv[1], line); //sets up queue based off of contents of input file
  int numStudents = line->getSize();
  int waitTimes[numStudents];
  int numWindows = sim->getWindows();
  int idleTimes[numWindows];
  int iterator = 0;
  MyWindow** wind = new MyWindow*[numWindows];
  for (int i = 0; i < numWindows; ++i) { //makes correct amount of windows
    wind[i] = new MyWindow();
  }
  while (true) { //runs until all windows are idle and no one is in line
    if (line->isEmpty()) {
      int idleWindows = 0;
      for (int i = 0; i < numWindows; ++i) {
        if (wind[i]->isWindowIdle()) {
          ++idleWindows;
        }
      }
      if (idleWindows == numWindows) {
        break; //breaks while loop when all windows are idle & line is empty
      }
    } //if this point in loop is reached, students are still being processed
    for (int i = 0; i < numWindows; ++i) { //if theres an idle window, puts first student in line into that window and sets window busy
      if (wind[i]->isWindowIdle() && !line->isEmpty()) {
        Student* s = line->peek();
        if (s->getTimeEnteringLine() <= clock) {
          line->remove();
          s->setWaitTime(clock-(s->getTimeEnteringLine()+iterator/numWindows));
          waitTimes[iterator++] = s->getWaitTime();
          wind[i]->setWindowBusy();
          wind[i]->setStudent(s);
        }
      }
    }
    for (int i = 0; i < numWindows; ++i) { //checks all students at windows, if they are done, set window to idle, if not done, update their time at window. Updates idle time of all idle windows.
      if (!wind[i]->isWindowIdle()) {
        if (wind[i]->getStudent()->getTimeAtWindow() == wind[i]->getStudent()->getTimeNeededAtWindow()) {
          wind[i]->setWindowIdle();
        } else {
          wind[i]->getStudent()->updateTimeAtWindow();
        }
      } else {
        wind[i]->updateIdleTime();
      }
    }
    ++clock;
  }
  for (int i = 0; i < numWindows; ++i) {
    idleTimes[i] = wind[i]->getIdleTime() - i;
  }
  stats->printStats(waitTimes, numStudents, idleTimes, numWindows);
  delete [] wind;
  delete line;
  delete sim;
  delete stats;
  return 0;
}
