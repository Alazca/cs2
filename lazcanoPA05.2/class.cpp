#include "class.h"

// default constructor
StringCS2::StringCS2() {
  c = new char[SIZE];
  len = 0;
  c[0] = '\0';
}

// copy constructor
StringCS2::StringCS2(const StringCS2& cpy) {
  c = new char[SIZE];
  len = cpy.len;
  strncpy(c, cpy.c, cpy.len);
  c[len] = '\0';
}

// creates a new character array after creation
StringCS2::StringCS2(const char* newStr) {
  c = new char[SIZE];
  len = strlen(newStr);
  strncpy(c, newStr, len);
  c[len] = '\0';
}

// converts int to string
StringCS2::StringCS2(int num) {
  c = new char[SIZE];
  len = 0;
  if (num == 0) {
    c[0] = '0';
    c[1] = '\0';
    len = 1;
  }
  // 0-9 digits (decimal system)
  for (len = 0; num > 0 && len < SIZE; len++) {
    int digit = num % 10;
    c[len] = digit + '0';
    num = num / 10;
  }
  if (len == 0) {
    c[len++] = '0';
  }
  c[len] = '\0';
  // reverses digits since it was pulled in opposite order
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    char temp = c[i];
    c[i] = c[j];
    c[j] = temp;
  }
}

// destructor
StringCS2::~StringCS2() {
  delete[] c;
}

// length member function
int StringCS2::length() const {
  return len;
}

// operator overload for assignment operator
StringCS2& StringCS2::operator=(const StringCS2& rhs) {
  if (this == &rhs) {
    return *this;
  }
  len = rhs.len;
  strncpy(c, rhs.c, len);
  c[len] = '\0';
  return *this;
}

// operator overload for assignment operator to assign character array to rvalue
StringCS2& StringCS2::operator=(const char* rhs) {
  len = strlen(rhs);
  strncpy(c, rhs, len);
  c[len] = '\0';
  return *this;
}

// operator overload for subscript
char& StringCS2::operator[](int index) const {
  if (index < 0 || index >= len) {
    cerr << "Error: Out of range" << endl;
    return c[0];
  }
  return c[index];
}

// check length first to see if same size,
bool StringCS2::operator==(const StringCS2& rhs) const {
  if (len != rhs.len) {
    return false;
  }

  for (int i = 0; i < len; i++) {
    if (c[i] != rhs.c[i]) {
      return false;
    }
  }

  return true;
}

// operator overload for <<
ostream& operator<<(ostream& os, const StringCS2& rhs) {
  os << rhs.c;
  return os;
}
