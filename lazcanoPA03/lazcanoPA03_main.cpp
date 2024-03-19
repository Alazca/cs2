/*
 * PA03_main.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: Andy Lazcano
 */

#include "PA03_class.hpp"

/*********************************************************************
 *                       DESCRIPTION:
 * The main function
 *
 * Loops through options for the user to enter worker information. User inputs
 * Name, Rate, and hours worked and the worker member function performs the
 *calculations. Displays total amount for payroll and how many workers
 *processed. Pre-conditions: N/A
 *
 * Post-conditions:
 * Exit.
 *
 ******************************************************************** */

int main() {
  Worker* workerRecord[SIZE] = { nullptr };
  int index = 0;
  string name, stringHours, stringRate;
  float totalPayRoll = 0;
  cout << "Enter Worker Name: " << endl;
  getline(cin, name);
  while (name != "STOP") {
    cout << "Enter Hours Worked: " << endl;
    getline(cin, stringHours);
    cout << "Enter Pay Rate: " << endl;
    getline(cin, stringRate);
    float hours = stof(stringHours);
    float rate = stof(stringRate);
    // new worker objects
    workerRecord[index] = new Worker();
    workerRecord[index]->setName(name);
    workerRecord[index]->setHours(hours);
    workerRecord[index]->setRate(rate);
    workerRecord[index]->payCalc();
    // display
    cout << fixed << setprecision(2)
         << "Hours Worked: " << workerRecord[index]->getHours()
         << ", rate: " << workerRecord[index]->getRate() << endl;
    cout << "Regular Pay: $" << workerRecord[index]->getRegPay()
         << ", Overtime pay: $" << workerRecord[index]->getOverPay()
         << ", Total Pay: $" << workerRecord[index]->getTotalPay() << endl;
    cout << setfill('-') << setw(25) << " " << endl;
    index++;
    cout << "Enter Worker Name: " << endl;
    getline(cin, name);
  }
  // displays process information and displays pay information for the sessionss
  cout << "We Processed " << index << " worker(s):" << endl;
  for (int i = 0; i < index; i++) {
    cout << workerRecord[i]->getName() << endl;
    totalPayRoll += workerRecord[i]->getTotalPay();
  }
  cout << "Total Payroll: $" << totalPayRoll << endl;
  cout << "PROGRAM ENDING. . ." << endl;
  return 0;
}
