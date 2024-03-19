#include "classes.h"
#include <iomanip>

// Constructor  derived classes, use initialized list
Beverage::Beverage(string name, string maker, string idBev_, float price,
                   int sold, char menu)
    : name(name),
      maker(maker),
      idBev_(idBev_),
      price(price),
      sold(sold),
      menu(menu) {}

Coffee::Coffee(string name, string maker, string idBev_, float price, int sold,
               char menu, char roast, string origin, int caffeine)
    : Beverage(name, maker, idBev_, price, sold, menu) {
  this->roast    = roast;
  this->origin   = origin;
  this->caffeine = caffeine;
}

Juice::Juice(string name, string maker, string idBev_, float price, int sold,
             char menu, string flavor, int calories, int percent, char blend)
    : Beverage(name, maker, idBev_, price, sold, menu) {
  this->flavor   = flavor;
  this->calories = calories;
  this->blend    = blend;
  this->percent  = percent;
}

Soda::Soda(string name, string maker, string idBev_, float price, int sold,
           char menu, string flavor, int calories, char caff_conf)
    : Beverage(name, maker, idBev_, price, sold, menu) {
  this->flavor   = flavor;
  this->calories = calories;
  this->caff     = caff_conf;
}

Tea::Tea(string name, string maker, string idBev_, float price, int sold,
         char menu, char c, string f, int caffeine)
    : Beverage(name, maker, idBev_, price, sold, menu) {
  this->color  = c;
  this->flavor = f;
  this->caff   = caffeine;
}

Water::Water(string name, string maker, string idBev_, float price, int sold,
             char menu, char filtered, char spring)
    : Beverage(name, maker, idBev_, price, sold, menu) {
  this->filtered = filtered;
  this->spring   = spring;
}

// Accessors  all derived classes
string Beverage::getidBev_() const {
  return idBev_;
}

char Coffee::getRoast() const {
  return roast;
}

string Coffee::getOrigin() const {
  return origin;
}

int Coffee::getCaff() const {
  return caffeine;
}

string Juice::getFlavor() const {
  return flavor;
}

int Juice::getCal() const {
  return calories;
}

int Juice::getPercent() const {
  return percent;
}

char Juice::getBlend() const {
  return blend;
}

char Tea::getColor() const {
  return color;
}

string Tea::getFlavor() const {
  return flavor;
}

int Tea::getCaff() const {
  return caff;
}

string Soda::getFlavor() const {
  return flavor;
}

int Soda::getCal() const {
  return calories;
}

char Soda::getCaff() const {
  return caff;
}

char Water::getFiltered() const {
  return filtered;
}

char Water::getSpring() const {
  return spring;
}

// Simple display, only displays doesn't need mat, 21 in 21 out, doesn't check
// individual derived classes members
void Beverage::display() {
  cout << this->idBev_ << " " << this->name << " " << this->maker << " $"
       << fixed << setprecision(2) << this->price << "   " << this->sold
       << this->menu << endl;
}

// Base display  common elements found in all classes
void Beverage::baseDisplay() {
  cout << "Name: " << this->name << " "
       << "Vendor: " << this->maker << " " << fixed << setprecision(2)
       << "Price: $" << this->price << " \n"
       << "Units Sold: " << this->sold << " " << endl;
  if (this->menu == 'y') {
    cout << "On the menu: Yes" << endl;
  } else {
    cout << "On the menu: No" << endl;
  }
}

void Beverage::drinkDisplay() {
  cout << "EasterEgg";
}

void Beverage::sales() {
  cout << "EasterEgg";
}

void Coffee::coffeeDisplay() const {
  cout << "Roast: " << this->getRoast() << "\tOrigin: " << this->getOrigin()
       << "\tCaffeine:" << this->getCaff() << endl;
}

void Juice::juiceDisplay() const {
  cout << "Flavor: " << this->getFlavor() << "\tCalories: " << this->getCal()
       << "\tPercent Juice: " << this->getPercent()
       << "\tBlend: " << this->getBlend() << endl;
}

void Tea::teaDisplay() const {
  cout << "Color: " << this->getColor() << "\tFlavor: " << this->getFlavor()
       << "\tCaffeine: " << this->getCaff() << endl;
}

void Soda::sodaDisplay() const {
  cout << "Flavor: " << this->getFlavor() << "\tCalories: " << this->getCal()
       << "\tCaffinated: " << this->getCaff() << endl;
}

void Water::waterDisplay() const {
  cout << "Filtered: " << this->getFiltered()
       << "\tSpring: " << this->getSpring() << endl;
}

void Coffee::coffeeSales() {
  cout << "\nTotal sold: " << this->sold;
  if (this->sold < 750 && this->getRoast() != 'd') {
    this->menu = 'n';
    cout << "\nThis item was taken off the menu for lack of sales";
  }
}

void Juice::juiceSales() {
  cout << "Total sold: " << this->sold;
  if (this->sold < 100 && this->getPercent() != 100) {
    this->menu = 'n';
    cout << "\nThis item was taken off the menu for lack of sales";
  }
}

void Tea::teaSales() {
  cout << "Total sold: " << this->sold;
  if (this->sold < 750 && this->getColor() != 'g') {
    this->menu = 'n';
    cout << "\nThis item was taken off the menu for lack of sales";
  }
}

void Soda::sodaSales() {
  cout << "Total sold: " << this->sold;
  if (this->sold < 1000) {
    this->menu = 'n';
    cout << "\nThis item was taken off the menu for lack of sales";
  }
}

void Water::waterSales() {
  cout << "Total sold: " << this->sold;
  if (this->sold < 300 && this->getSpring() != 'y') {
    this->menu = 'n';
    cout << "\nThis item was taken off the menu for lack of sales";
  }
}
