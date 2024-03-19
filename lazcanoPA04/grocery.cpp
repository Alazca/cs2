#include "grocery.hpp"

// Accessor member functions if needed to change to private

string Grocery::getDescription() const {
  return description;
}

float Grocery::getUpc() const {
  return upc;
}

float Grocery::getCost() const {
  return cost;
}

float Grocery::getPrice() const {
  return price;
}

int Grocery::getInventory() const {
  return inventory;
}

char Grocery::getStatus() const {
  return status;
}

int Grocery::getHistItems() const {
  return numHistItems;
}

// Mutator to set status to user input if needed to convert to private

void Grocery::setStatus(char s) {
  status = s;
}

void Grocery::updateGroceryItems() {
  numGroceryItems++;
}

// comparison overload for item upc (==)
bool Grocery::operator==(const Grocery& upc2) {
  return (this->numHistItems == upc2.numHistItems);
}

int Grocery::numGroceryItems = 0;
