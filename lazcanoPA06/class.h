/*
 * class.h
 *
 * Container and Element ADT.  Utilized templates for key/data pairs.
 *
 *
 *
 *  Created on: Apr 18, 2023
 *      Author: andyl
 */

#ifndef CLASS_H_
#define CLASS_H_

#include <unistd.h>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

template <class KeyType, class DataType>
struct Element {
  KeyType key;
  DataType data;
  int priority;
  string timestamp;
};

template <class KeyType, class DataType>
class Container {
private:
  int s;
  // max size
  int capacity;
  // Dynamically Allocated Data Type
  Element<KeyType, DataType>* dataElement;
  // position for get_next
  int index;

public:
  Container();
  Container(int);
  ~Container();
  int size() const;
  int max_size() const;
  bool start();
  bool push(Element<KeyType, DataType>&);
  bool get_front(Element<KeyType, DataType>&) const;
  bool get_back(Element<KeyType, DataType>&) const;
  bool get_next(Element<KeyType, DataType>&);
  bool get_by_key(Element<KeyType, DataType>&) const;
  bool get_highest_priority(Element<KeyType, DataType>&) const;
  Element<KeyType, DataType>& operator[](int);
};

// Constructor for empty command line arguments array
template <class KeyType, class DataType>
Container<KeyType, DataType>::Container() {
  s = 0;
  capacity = 0;
  dataElement = { nullptr };
  index = 0;
}

// Constructor for Command Line Argument array
template <class KeyType, class DataType>
Container<KeyType, DataType>::Container(int num) {
  s = 0;
  capacity = num;
  dataElement = new Element<KeyType, DataType>[capacity];
  index = 0;
}

// D-stor
template <class Key, class Data>
Container<Key, Data>::~Container() {
  delete[] dataElement;
}

// Size function
template <class KeyType, class DataType>
int Container<KeyType, DataType>::size() const {
  return s;
}

// Max capacity function
template <class KeyType, class DataType>
int Container<KeyType, DataType>::max_size() const {
  return capacity;
}

// Push function. Provides time metadata for time and priority
template <class KeyType, class DataType>
bool Container<KeyType, DataType>::push(Element<KeyType, DataType>& element) {
  if (s < capacity) {
    time_t now = time(0);
    dataElement[s] = element;
    dataElement[s].timestamp = string(asctime(localtime(&now)));
    s++;
    return true;
  }
  return false;
}

template <class KeyType, class DataType>
bool Container<KeyType, DataType>::get_front(
    Element<KeyType, DataType>& element) const {
  if (s > 0) {
    element = dataElement[0];
    return true;
  }
  return false;
}

template <class KeyType, class DataType>
bool Container<KeyType, DataType>::get_back(
    Element<KeyType, DataType>& element) const {
  if (s > 0) {
    element = dataElement[s - 1];
    return true;
  }
  return false;
}

template <class KeyType, class DataType>
bool Container<KeyType, DataType>::start() {
  if (s > 0) {
    return true;
  }
  return false;
}

template <class KeyType, class DataType>
bool Container<KeyType, DataType>::get_next(
    Element<KeyType, DataType>& element) {
  if (index >= s) {
    return false;
  }
  element = dataElement[index];
  index++;
  return true;
}

template <class KeyType, class DataType>
bool Container<KeyType, DataType>::get_by_key(
    Element<KeyType, DataType>& element) const {
  for (int i = 0; i < s; i++) {
    if (dataElement[i].key == element.key) {
      element = dataElement[i];
      return true;
    }
  }
  return false;
}

template <class KeyType, class DataType>
bool Container<KeyType, DataType>::get_highest_priority(
    Element<KeyType, DataType>& element) const {
  int highIndex = 0;
  if (s == 0) {
    return false;
  }
  for (int i = 0; i < s; i++) {
    if (dataElement[i].priority > dataElement[highIndex].priority) {
      highIndex = i;
    }
  }
  element = dataElement[highIndex];
  return true;
}

template <class KeyType, class DataType>
Element<KeyType, DataType>& Container<KeyType, DataType>::operator[](
    int index) {
  if (index < 0 || index >= s) {
    throw string("Error: Index out of range");
  }
  return dataElement[index];
}

#endif /* CLASS_H_ */
