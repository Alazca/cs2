/*
 * phistory.hpp
 *
 *  Created on: Mar 13, 2023
 *      Author: Andy Lazcano
 */

#ifndef PHISTORY_HPP_
#define PHISTORY_HPP_
#include "main.hpp"

class PriceHistory {
public:
  // members
  float historicalPrice;
  string date;  // user enters in the form YYYY-MM-DD

  // mutators
  void setHprice(float);
  void setDate(string);

  // accessors
  float getHP() const;
  string getDate() const;
  friend class Grocery;
};

#endif /* PHISTORY_HPP_ */
