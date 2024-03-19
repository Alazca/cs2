/*
 * grocery.hpp
 *
 *  Created on: Mar 13, 2023
 *      Author: Andy Lazcano
 */

#ifndef GROCERY_HPP_
#define GROCERY_HPP_
#include "phistory.hpp"

/*******************************************
 *
 *            CLASS DEFINITION
 *
 *                 Grocery
 *
 *******************************************/

class Grocery {
public:
  // Array size for price history objects
  string description;
  int upc;
  float cost;
  float price;
  int inventory;
  char status;
  // counter for history items
  int numHistItems = 0;
  // counter for grocery items
  static int numGroceryItems;
  PriceHistory priceHistory[PH_SIZE];
  // accessors
  string getDescription() const;
  float getUpc() const;
  float getCost() const;
  float getPrice() const;
  int getInventory() const;
  char getStatus() const;
  int getHistItems() const;
  // mutators
  void setStatus(char);
  void updateGroceryItems();
  bool operator==(const Grocery&);
};

#endif /* GROCERY_HPP_ */
