/*
 * class.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Andy Lazcano
 */

#ifndef CLASS_H_
#define CLASS_H_

#include <cstring>
#include <iostream>
using namespace std;

// global for maximum string sizes
const int SIZE = 100;

class StringCS2 {
private:
  char* c;
  int len;

public:
  StringCS2();
  StringCS2(const int);
  StringCS2(const char*);
  StringCS2(const StringCS2&);
  ~StringCS2();
  int length() const;
  StringCS2& operator=(const StringCS2&);
  StringCS2& operator=(const char*);
  char& operator[](int) const;
  bool operator==(const StringCS2&) const;
  friend ostream& operator<<(ostream&, const StringCS2&);
};

#endif /* CLASS_H_ */
