#include "displayfunctions.hpp"
#include "grocery.hpp"

/*********************************************************************
 *                       DESCRIPTION:
 * The main function
 *
 * Gathers data and populates a static array. Converts data to integers as
 *applicable and stores into array.
 *
 * Displays menu.
 *
 * Allows user input to modify price history of grocery items.
 *
 * Pre-conditions:
 * N/A
 *
 * Post-conditions:
 * Exit.
 *
 ******************************************************************** */

int main() {
  // static array of grocery items to max size.
  Grocery groceryItem[MAX_SIZE];
  // reads the file
  ifstream inputData;
  // string to hold records
  string record;
  // grocery item initialization
  string strDescript;
  string userChoice;
  int strUpc, strInvent = 0;
  float strCost, strPrice = 0.0;
  char nStatus = '\0';
  // read file
  inputData.open("a4data.txt", ios::in);
  if (!inputData.is_open()) {
    cout << "Error Opening data file! Please check for document." << endl;
    exit(EXIT_FAILURE);
  }
  // populates grocery items from record
  for (int i = 0; getline(inputData, record); i++) {
    strUpc = stoi(record.substr(0, 6));
    strDescript = record.substr(6, 20);
    strCost = stof(record.substr(26, 6));
    strPrice = stof(record.substr(32, 6));
    strInvent = stoi(record.substr(38, 3));
    nStatus = record[41];

    groceryItem[i].description = strDescript;
    groceryItem[i].upc = strUpc;
    groceryItem[i].cost = strCost;
    groceryItem[i].price = strPrice;
    groceryItem[i].inventory = strInvent;
    groceryItem[i].status = nStatus;
    Grocery::numGroceryItems++;
  }
  displayHeader();
  for (int i = 0; i < Grocery::numGroceryItems; i++) {
    displayData(groceryItem[i]);
  }
  cout << endl;
  cout << "Please choose one of the following: " << endl;
  cout << "D-Display / H- Update UPC / "
          "C-Compare UPC / X- Close and Logout"
       << endl;
  getline(cin, userChoice);
  while (userChoice != "X") {
    if (userChoice == "D") {
      displayHeader();
      for (int i = 0; i < Grocery::numGroceryItems; i++) {
        displayData(groceryItem[i]);
        if (groceryItem[i].numHistItems > 0) {
          cout << "\tPrice History: ";
          for (int j = 0; j < groceryItem[i].numHistItems; i++) {
            cout << groceryItem[i].priceHistory[j].date << " "
                 << groceryItem[i].priceHistory[j].historicalPrice << endl;
          }
        } else {
          cout << "\tPrice History: There is no price history for this item."
               << endl;
        }
      }
    }
    if (userChoice == "H") {
      bool usercheck = false;
      string userInput;
      float userPrice;
      int userUpc;
      cout << "Please Search for an item by UPC: " << endl;
      getline(cin, userInput);
      userUpc = stoi(userInput);
      for (int i = 0; i < PH_SIZE; i++) {
        if (userUpc == groceryItem[i].upc) {
          usercheck = true;
          cout << "Please enter a date of price (Format YYYY-MM-DD): ";
          getline(cin, userInput);
          groceryItem[i].priceHistory[groceryItem[i].numHistItems].date =
              userInput;
          cout << "Please enter a price (Format X.XX): ";
          getline(cin, userInput);
          userPrice = stof(userInput);
          groceryItem[i]
              .priceHistory[groceryItem[i].numHistItems]
              .historicalPrice = userPrice;
          groceryItem[i].numHistItems++;
        }
      }
      if (!usercheck) {
        cout << "Object Not Found!";
      }
    }
    if (userChoice == "C") {
      int upc1, upc2;
      string userInputC;
      int index1;
      int index2;
      bool usercheckC = false;
      bool usercheckC2 = false;
      cout << "Enter the first UPC to compare: ";
      getline(cin, userInputC);
      upc1 = stoi(userInputC);
      cout << "Enter the second UPC to compare: ";
      getline(cin, userInputC);
      upc2 = stoi(userInputC);
      for (int i = 0; i < PH_SIZE; i++) {
        if (upc1 == groceryItem[i].upc) {
          usercheckC = true;
          index1 = i;
        }
        if (upc2 == groceryItem[i].upc) {
          usercheckC2 = true;
          index2 = i;
        }
      }
      if (!usercheckC || !usercheckC2) {
        cout << "Item not found" << endl;
      }
      if (groceryItem[index1] == groceryItem[index2]) {
        cout << "They are equal" << endl;
      } else {
        cout << "They are not equal" << endl;
      }
    }
    cout << endl;
    cout << "Please choose one of the following: " << endl;
    cout << "D-Display / H- Update UPC / "
            "C-Compare UPC / X- Close and Logout"
         << endl;
    getline(cin, userChoice);
  }
  // clean up section
  cout << "Have a good day!";
  inputData.close();

  return 0;
}
