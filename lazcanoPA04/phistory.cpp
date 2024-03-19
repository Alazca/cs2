#include "phistory.hpp"
#include "main.hpp"

// Mutator member functions if class is switched to private

void PriceHistory::setHprice(float p) {
  historicalPrice = p;
}

void PriceHistory::setDate(string d) {
  date = d;
}

float PriceHistory::getHP() const {
  return historicalPrice;
}

string PriceHistory::getDate() const {
  return date;
}
