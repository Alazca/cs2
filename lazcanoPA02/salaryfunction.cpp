#include <iostream>
#include "salaryheader.hpp"
using namespace std;

/***********************************************************************************
 *                       DESCRIPTION:
 * Average Salary function
 *
 * Calculates the average salary and also sends back the address of the highest
 *salary instructor
 *
 * Pre-conditions:
 * - A pointer array of type <Instructor>
 * - A pointer of type Instructor purposed to give salary information by address
 *
 * Post-conditions:
 * - An integer with the average salary
 * - The address of the highest paid instructor passed by reference
 *
 **********************************************************************************
 */

int averageSalary(Instructor* instructorArray[],
                  Instructor*& instructorSalary) {
  int totalSalary = 0;
  int averageSalary = 0;
  // Determines the amount of objects has been passed into this function
  int totalInstructors = 0;
  instructorArray[SIZE] = { nullptr };
  instructorSalary = instructorArray[0];
  Instructor* highestSalary = nullptr;
  for (int i = 0; instructorArray[i] != nullptr; i++) {
    totalSalary += instructorArray[i]->salary;
    if (highestSalary == nullptr ||
        instructorArray[i]->salary > highestSalary->salary) {
      highestSalary = instructorArray[i];
    }
    totalInstructors++;
  }
  instructorSalary = highestSalary;
  averageSalary = totalSalary / totalInstructors;
  cout << "Average Salary: $" << averageSalary << endl;
  cout << "Highest Salary: " << instructorSalary->firstName << " "
       << instructorSalary->lastName;
  return averageSalary;
}
