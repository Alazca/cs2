#include "PA03_class.hpp"

/*********************************************************************
 *                       DESCRIPTION:
 * The worker member function
 *
 * The accessors and mutators for the <worker> class. Member function performs
 * pay calculations consisting of regular pay, overtime pay, and total pay.
 *
 * Pre-conditions:
 * N/A
 *
 * Post-conditions:
 * Through a pointer array, sends pay information for use with main function.
 *
 ******************************************************************** */

// constructor to default numerical values to 0.
Worker::Worker(){
	hours = 0.0;
	rate = 0.0;
	regPay = 0.0;
	overPay= 0.0;
	totalPay = 0.0;
}

/******************************
 * 		Accessors
 *
 * *****************************/



string Worker::getName() const{
	return name;
}

float Worker::getHours() const{
	return hours;
}

float Worker::getRate() const {
	return rate;
}

float Worker::getRegPay() const{
	return regPay;
}

float Worker::getOverPay() const{
	return overPay;
}

float Worker::getTotalPay() const{
	return totalPay;
}

/******************************
 * 		Mutators
 *
 * *****************************/

void Worker::setName(string n){
	name = n;
}

void Worker::setHours(float h){
	hours = h;
}

void Worker::setRate(float r){
	rate = r;
}


/******************************
 * 		Calculation
 * 		Member Function
 *
 * *****************************/

void Worker::payCalc(){
	if (hours <= 40){
		regPay = hours * rate;
		overPay = 0;
	}
	else if(hours > 40){
		regPay = 40 * rate;
		overPay = (hours - 40) * (1.5 * rate);
	}
	totalPay = regPay + overPay;
}

