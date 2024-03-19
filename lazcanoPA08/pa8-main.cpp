#include "class.h"
#include <fstream>
#include <iomanip>

int main(){
	// Initialization of variables standard to reading files
	ifstream dataFile;
	string input;
	string name_;
	string id_;
	float tuition_;
	// Keeps track of student objects
	int sCtr = 0;
	Student students[SIZE];
	dataFile.open("a8data.txt", ios::in);
		if (!dataFile.is_open()) {
			cout << "Error Opening a8data! Please check for document." << endl;
			exit(EXIT_FAILURE);
		}
	while(getline(dataFile, input)){
		name_ = input.substr(0,20);
		id_ = input.substr(20, 5);
		tuition_ = stof(input.substr(25,7));
		students[sCtr].setName(name_);
		students[sCtr].setId(id_);
		students[sCtr].setTuition(tuition_);
		sCtr++;
	}
	// Close and clean-up
	dataFile.close();
	cout << setfill('=') << setw(50) << " " << setfill(' ') << endl;
	cout << "Name:" << setw(20) << " " << "ID#:"
		 << setw(15) << "Tuition: " <<	endl;
	cout << setfill('=') << setw(50) << " " << setfill(' ') << endl;
	for (int i = 0; i < sCtr; i++){
		cout << left << students[i].getName() << setw(5)
			 << " " << students[i].getId() << setw(5) << " "
			 << "$" << students[i].getTuition() << endl;
	}
	bool (*comparePtr) (Student, Student) = compareFunc;
	void (*swapPtr) (Student&, Student&) = swapFunc;
	TheSort<Student> sortIt(students, sCtr, comparePtr, swapPtr);
	sortIt.sortAlgo();
	cout << "\n\tSorted Array By Name\n" << endl;
	cout << "Name:" << setw(15) << " " << "ID#: " << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < sCtr;i++){
		cout << students[i].getName()
		 	 << students[i].getId() << endl;
	}
	return 0;
}
