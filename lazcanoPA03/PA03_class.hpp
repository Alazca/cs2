/*
 * PA03_struct.hpp
 *
 *  Created on: Mar 1, 2023
 *      Author: Andy Lazcano
 */

#ifndef PA03_CLASS_HPP_
#define PA03_CLASS_HPP_

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

////////////////////////////////////////
// 		CLASS definition  		   //
///////////////////////////////////////

class Worker {
	private:
		string name;
		float hours;
		float rate;
		float regPay;
		float overPay;
		float totalPay;
	public:
		// constructor
		Worker();
		// accessors
		string getName() const;
		float getHours() const;
		float getRate() const;
		float getRegPay() const;
		float getOverPay() const;
		float getTotalPay() const;
		// mutators
		void setName(string);
		void setHours(float);
		void setRate(float);
		// functions
		void payCalc();
		// default destructor
		~Worker();
};

// Global variable for statically allocated array
const int SIZE = 100;

#endif /* PA03_CLASS_HPP_ */
