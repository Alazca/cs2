#include "pa2_ADTs.hpp"
#include "salaryheader.hpp"

/*********************************************************************
 *                       DESCRIPTION:
 * The main function
 *
 * Performs the initial file read and checks to see if its valid. Provides user
 * feedback if the file didn't open. Read's the file and populates objects based on the
 * struct <Instructor> and displays information. Calls the salary function to highlight the average
 * and highest salary. Deallocates memory and closes file.
 *
 * Pre-conditions:
 * N/A
 *
 * Post-conditions:
 * Natural Exit.
 *
 ******************************************************************** */

int main(){
	const int DISPLAY = 15;
	int buffer = 46;
	// character array to hold entire record of instructors from file with the data size as the size of the array
	char record[buffer];
	// for use with salary function
	Instructor* highestSalary = nullptr;
	ifstream dataFile;
	dataFile.open("pa2data", ios::in);
	if(!dataFile.is_open()){
		cout << "Error Opening PA02data! Please check for document." << endl;
		exit(EXIT_FAILURE);
	}
	// Pointer array to manage all the instructor objects this is the same as looping
	// Dynamically allocate and initialize each element of instructor record to null pointer.
	Instructor* instructorRecord[SIZE] = {nullptr};
	// reads the data and creates new objects of instructors based on the file its reading
	while(!dataFile.eof()){
		for (int i = 0; dataFile.read(record, buffer); i++)
		{
			instructorRecord[i] = new Instructor();
		    char charEmployeeId[10], charLastName[15], charMI[2],
		         charFirstName[10], charDepartment[6], charSalary[7];
	        strncpy(charEmployeeId, record, 9);
	        charEmployeeId[9] = '\0';
	        strncpy(charFirstName, record + 9, 9);
	        charFirstName[9] = '\0';
	        strncpy(charMI, record + 19, 1);
	        charMI[1] = '\0';
	        strncpy(charLastName, record + 20, 14);
	        charLastName[14] = '\0';
	        strncpy(charDepartment, record + 35, 5);
	        charDepartment[5] = '\0';
	        strncpy(charSalary, record + 40, 6);
	        charSalary[6] = '\0';
			instructorRecord[i]->id = charEmployeeId;
			instructorRecord[i]->lastName = charLastName;
			instructorRecord[i]->middleInit = charMI[0];
			instructorRecord[i]->firstName = charFirstName;
			instructorRecord[i]->department = charDepartment;
			instructorRecord[i]->salary = atoi(charSalary);
		}
	}

	// close connection to file
	dataFile.close();
	// Displays the record from the file
	cout << left << setw(DISPLAY)  << "Employee ID"
		 << left << setw(DISPLAY)  << "Last Name"
		 << left << setw(8)  	   << "MI"
		 << left << setw(DISPLAY)  << "First Name"
		 << left << setw(DISPLAY)  << "Department"
		 << left << setw(DISPLAY)  << "Salary" << endl;
	cout << right << setw(80) << setfill('=') << " " << setfill(' ') << endl;
	for (int i = 0; instructorRecord[i] != nullptr; i++){
		cout << left << setw(DISPLAY) << instructorRecord[i]->id
			 << setw(DISPLAY) << instructorRecord[i]->lastName
			 << setw(8) 	  << instructorRecord[i]->middleInit
			 << setw(DISPLAY) << instructorRecord[i]->firstName
			 << setw(DISPLAY) << instructorRecord[i]->department
			 << "$" << instructorRecord[i]->salary << " " << endl;
	}
	cout << endl;
	// Invokes salary. Returns an integer for average salary and also references highest paid instructor
	averageSalary(instructorRecord, highestSalary);
	// deletes allocated pointers and cleans up
	for (int i = 0; i < SIZE; i++){
		delete instructorRecord[i];
	}
	//terminate
	return 0;
}
