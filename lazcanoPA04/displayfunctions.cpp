#include "displayfunctions.hpp"
#include "grocery.hpp"

/*********************************************************************
 *                       DESCRIPTION:
 *
 * Display functions to modify menu quickly as needed and used as needed

 *
 * Allows user input to modify price history of grocery items.
 *
 * Pre-conditions:
 * Grocery array to display data.
 *
 * Post-conditions:
 * N/A
 *
 ******************************************************************** */

void displayHeader() {
  const int DISPLAY_SIZE = 100;
  cout << setfill('=') << setw(DISPLAY_SIZE) << " " << setfill(' ') << endl;
  cout << "UPC" << setw(13) << " "
       << "Description" << setw(23) << "Cost" << setw(15) << "Price" << setw(18)
       << "Inventory" << setw(12) << "Status" << endl;
  cout << setfill('=') << setw(DISPLAY_SIZE) << " " << setfill(' ') << endl;
}

void displayData(Grocery array) {
  cout << "0" << array.upc << setw(10) << " " << array.description << setw(10)
       << " " << fixed << setprecision(2) << array.cost << setw(10) << " "
       << fixed << setprecision(2) << array.price << setw(10) << " "
       << array.inventory << setw(10) << " "
       << "\t" << array.status << " " << endl;
}
