/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the implementation .cpp file for the Stats class.
*/
#include "Stats.h"

Stats::Stats() {

}

Stats::~Stats() {

}

void Stats::printStats(int waitTimes[], int numStudents, int idleTimes[], int numWindows) {
  cout << "Mean student wait time: " << calcMeanWaitTime(waitTimes, numStudents) << endl;
  cout << "Median student wait time: " << calcMedianWaitTime(waitTimes, numStudents) << endl;
  cout << "Longest student wait time: " << longestWaitTime(waitTimes, numStudents) << endl;
  cout << "Number of students waiting over 10 minutes: " << studentsWaitingOver10(waitTimes, numStudents) << endl;
  cout << "Mean window idle time: " << calcMeanIdleTime(idleTimes, numWindows) << endl;
  cout << "Longest window idle time: " << longestIdleTime(idleTimes, numWindows) << endl;
  cout << "Number of windows idle for over 5 minutes: " << windowsIdleOver5(idleTimes, numWindows) << endl;
}

double Stats::calcMeanWaitTime(int waitTimes[], int numStudents) {
  double mean = 0;
  for (int i = 0; i < numStudents; ++i) {
    mean += waitTimes[i];
  }
  return mean / numStudents;
}

int Stats::calcMedianWaitTime(int waitTimes[], int numStudents) {
  return waitTimes[numStudents/2];
}

int Stats::longestWaitTime(int waitTimes[], int numStudents) {
  int longest = 0;
  for (int i = 0; i < numStudents; ++i) {
    if (waitTimes[i] > longest) {
      longest = waitTimes[i];
    }
  }
  return longest;
}

int Stats::studentsWaitingOver10(int waitTimes[], int numStudents) {
  int waitedOver10 = 0;
  for (int i = 0; i < numStudents; ++i) {
    if (waitTimes[i] > 10) {
      ++waitedOver10;
    }
  }
  return waitedOver10;
}

double Stats::calcMeanIdleTime(int idleTimes[], int numWindows) {
  double mean = 0;
  for (int i = 0; i < numWindows; ++i) {
    mean += idleTimes[i];
  }
  return mean / numWindows;
}

int Stats::longestIdleTime(int idleTimes[], int numWindows) {
  int longest = 0;
  for (int i = 0; i < numWindows; ++i) {
    if (idleTimes[i] > longest) {
      longest = idleTimes[i];
    }
  }
  return longest;
}

int Stats::windowsIdleOver5(int idleTimes[], int numWindows) {
  int idleOver5 = 0;
  for (int i = 0; i < numWindows; ++i) {
    if (idleTimes[i] > 5) {
      ++idleOver5;
    }
  }
  return idleOver5;
}
