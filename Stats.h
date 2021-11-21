/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 5 - Registrar’s Office Simulation
 * This is the header .h file for the Stats class
*/
#ifndef STATS_H
#define STATS_H
#include <iostream>
using namespace std;

class Stats {
public:
  Stats(); //default constructor
  ~Stats(); //default destructor
  void printStats(int waitTimes[], int numStudents, int idleTimes[], int numWindows); //prints all stats by calling other Stats methods
  double calcMeanWaitTime(int waitTimes[], int numStudents); //finds and returns the mean wait time of students
  int calcMedianWaitTime(int waitTimes[], int numStudents); // finds and returns the median wait time of students
  int longestWaitTime(int waitTimes[], int numStudents); // finds and returns the longest wait time of students
  int studentsWaitingOver10(int waitTimes[], int numStudents); // finds and returns the number of students waiting over 10 min
  double calcMeanIdleTime(int idleTimes[], int numWindows); // finds and returns the mean idle time of windows
  int longestIdleTime(int idleTimes[], int numWindows); // finds and returns the longest idel time of windows
  int windowsIdleOver5(int idleTimes[], int numWindows); // finds and returns the number of windows idle over 5 min

};

#endif
