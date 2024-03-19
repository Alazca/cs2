/*
 * class.h
 *
 *  Created on: May 3, 2023
 *      Author: Andy Lazcano
 */

#ifndef CLASS_H_
#define CLASS_H_
#include <iostream>
#include <algorithm>

using namespace std;

// Max Size
const int SIZE = 100;

class Student{
private:
	string name;
	string id;
	float tuition;
public:
	string getName();
	string getId();
	float getTuition();
	void setName(string);
	void setId(string);
	void setTuition(float);
};

template<class S>
class TheSort {
private:
	S *data;
	int sizeData;
	bool (*compare)(S, S);
	void (*swap)(S&, S&);
public:
	TheSort(S* data, int sizeData, bool (*compare)(S, S), void (*swap)(S&, S&));
	void sortAlgo();
};

template<class S>
TheSort<S>::TheSort(S* data, int sizeData, bool (*compare)(S, S), void (*swap)(S&, S&)){
	this->data = data;
	this->sizeData = sizeData;
	this->compare = compare;
	this->swap = swap;
}

template<class S>
void TheSort<S>::sortAlgo() {
	for (int i = 0; i < sizeData - 1; i++) {
		for (int j = 0; j < sizeData - i - 1; j++) {
			if (compare(data[j], data[j + 1])) {
				swap(data[j], data[j + 1]);
			}
		}
	}
}

bool compareFunc(Student,Student);
void swapFunc(Student&, Student&);

#endif /* CLASS_H_ */
