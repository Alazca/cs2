/*
 * ADTs.hpp
 * for PA02 assignment
 *
 *  Created on: Feb 15, 2023
 *      Author: Andy Lazcano
 */

#ifndef PA2_ADTS_HPP_
#define PA2_ADTS_HPP_
#include <istream>
using namespace std;

/*****************************************************
 *             ADTs and Function Prototypes          *
 * ***************************************************/

struct Instructor {
  string id;
  string lastName;
  string firstName;
  string department;
  char middleInit;
  int instructorNumber;
  int salary;
};

// Global variable for array size as required by specification
const int SIZE = 100;

#endif /* PA2_ADTS_HPP_ */
