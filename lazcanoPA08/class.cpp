#include "class.h"


void Student::setName(string n){
	name = n;
}

void Student::setId(string i){
	id = i;
}

void Student::setTuition(float t){
	tuition = t;
}

string Student::getName(){
	return name;
}

string Student::getId(){
	return id;
}

float Student::getTuition(){
	return tuition;
}

bool compareFunc(Student a, Student b){
	return a.getName() > b.getName();
}

void swapFunc(Student& a, Student& b){
	Student swap = a;
	a = b;
	b = swap;
}
