#include <fstream>
#include <iostream>
#include "classes.h"

int main() {
  // counter to keep track of objects
  int bevCtr = 0;
  ifstream dataFile;
  // Base class variables
  string name, maker, idBev_;
  char menu, id;
  int sold;
  float price;
  string user;
  // Open project
  dataFile.open("a7data.txt", ios::in);
  if (!dataFile.is_open()) {
    cout << "Error Opening a7data! Please check for document." << endl;
    exit(EXIT_FAILURE);
  }
  // populate array
  Beverage* bevArr[SIZE] = { nullptr };
  // Pointer for all objects
  string data;
  // variable variants are annotated by underscores after
  while (getline(dataFile, data)) {
    idBev_ = data.substr(0, 4);
    name = data.substr(4, 20);
    maker = data.substr(24, 15);
    price = stof(data.substr(39, 5));
    sold = stoi(data.substr(44, 4));
    id = data[0];
    menu = data[48];
    switch (id) {
      case 'C': {
        char roast = data[49];
        string origin = data.substr(50, 10);
        int caffeine = stoi(data.substr(60, 3));
        bevArr[bevCtr] = new Coffee(name, maker, idBev_, price, sold, menu,
                                    roast, origin, caffeine);
        break;
      }
      case 'J': {
        string flavor = data.substr(49, 10);
        int calories = stoi(data.substr(59, 3));
        int percent = stoi(data.substr(62, 3));
        char blend = data.substr(65)[0];
        bevArr[bevCtr] = new Juice(name, maker, idBev_, price, sold, menu,
                                   flavor, calories, percent, blend);
        break;
      }
      case 'T': {
        char color = data[49];
        int caffeine = stoi(data.substr(50, 3));
        string flavor = data.substr(53);
        bevArr[bevCtr] = new Tea(name, maker, idBev_, price, sold, menu, color,
                                 flavor, caffeine);
        break;
      }
      case 'S': {
        string flavor = data.substr(49, 10);
        int calories = stoi(data.substr(59, 3));
        char caff_conf = data[62];
        bevArr[bevCtr] = new Soda(name, maker, idBev_, price, sold, menu,
                                  flavor, calories, caff_conf);
        break;
      }
      case 'W': {
        char filtered = data[49];
        char spring = data[50];
        bevArr[bevCtr] =
            new Water(name, maker, idBev_, price, sold, menu, filtered, spring);
        break;
      }
      default:
        cout << "Unknown beverage ID: " << id << endl;
    }
    bevCtr++;
  }
  cout << "--------------  TEST	TEST	TEST------------------\n";
  //	Loops through array and displays on console- matches test data, 21 in 21
  //out
  //  This is only used to parse through data. AS REQUESTED
  for (int i = 0; i < bevCtr; i++) {
    cout << i + 1 << " ";
    bevArr[i]->display();
    cout << endl;
  }
  cout << "Please enter a Beverage ID (0000 to stop) : " << endl;
  getline(cin, user);
  while (user != "0000") {
    bool flag = false;
    for (int i = 0; i < bevCtr; i++) {
      if (user == bevArr[i]->getidBev_()) {
        flag = true;
        bevArr[i]->baseDisplay();
        bevArr[i]->drinkDisplay();
        bevArr[i]->sales();
      }
    }
    if (!flag) {
      cout << "Item Not Found" << endl;
    }
    cout << "\nPlease enter another ID: " << endl;
    getline(cin, user);
  }
  // virtual display
  for (int i = 0; i < bevCtr; i++) {
    bevArr[i]->baseDisplay();
    bevArr[i]->drinkDisplay();
    cout << endl;
  }
  cout << "	Have a good day!	";
  // clean up
  dataFile.close();
  for (int i = 0; i <= bevCtr; i++) {
    delete bevArr[i];
  }
  return 0;
}
