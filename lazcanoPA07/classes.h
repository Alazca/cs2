/*
 * classes.h
 *
 *  Created on: May 2, 2023
 *      Author: Andy Lazcano
 *
 *      Base class and derived classes for Beverages.
 *      Destructors were coded in-line for simplicity.
 *      Virtual Display functions were also coded in-line for simplicity.
 *
 */

#ifndef CLASSES_H_
#define CLASSES_H_
#include <iostream>
using namespace std;

// Max Record Size
const int SIZE = 100;

class Beverage {
protected:
  string name;
  string maker;
  string idBev_;
  float price;
  int sold;
  char menu;

public:
  Beverage(string, string, string, float, int, char);
  string getidBev_() const;
  void display();
  virtual void baseDisplay();
  virtual void drinkDisplay();
  virtual void sales();
  virtual ~Beverage(){};
};

class Coffee : public Beverage {
private:
  char roast;
  string origin;
  int caffeine;

public:
  Coffee(string, string, string, float, int, char, char, string, int);
  ~Coffee(){};
  char getRoast() const;
  string getOrigin() const;
  int getCaff() const;
  void coffeeDisplay() const;

  void drinkDisplay() override {
    coffeeDisplay();
  };

  void coffeeSales();

  void sales() override {
    coffeeSales();
  };
};

class Juice : public Beverage {
private:
  string flavor;
  int calories;
  int percent;
  char blend;

public:
  Juice(string, string, string, float, int, char, string, int, int, char);
  ~Juice(){};
  string getFlavor() const;
  int getCal() const;
  int getPercent() const;
  char getBlend() const;
  void juiceDisplay() const;

  void drinkDisplay() override {
    juiceDisplay();
  };

  void juiceSales();

  void sales() override {
    juiceSales();
  };
};

class Tea : public Beverage {
private:
  char color;
  string flavor;
  int caff;

public:
  Tea(string, string, string, float, int, char, char, string, int);
  ~Tea(){};
  char getColor() const;
  string getFlavor() const;
  int getCaff() const;
  void teaDisplay() const;

  void drinkDisplay() override {
    teaDisplay();
  };

  void teaSales();

  void sales() override {
    teaSales();
  };
};

class Soda : public Beverage {
private:
  string flavor;
  int calories;
  char caff;

public:
  Soda(string, string, string, float, int, char, string, int, char);
  ~Soda(){};
  string getFlavor() const;
  int getCal() const;
  char getCaff() const;
  void sodaDisplay() const;

  void drinkDisplay() override {
    sodaDisplay();
  };

  void sodaSales();

  void sales() override {
    sodaSales();
  };
};

class Water : public Beverage {
private:
  char filtered;
  char spring;

public:
  Water(string, string, string, float, int, char, char, char);
  ~Water(){};
  char getFiltered() const;
  char getSpring() const;
  void waterDisplay() const;

  void drinkDisplay() override {
    waterDisplay();
  };

  void waterSales();

  void sales() override {
    waterSales();
  };
};

#endif /* CLASSES_H_ */
