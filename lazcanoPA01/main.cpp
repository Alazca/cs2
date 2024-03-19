#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;
/*********************************************************************
 *                       FUNCTION PROTOTYPES
 ******************************************************************** */

void createArray(const int, int*&);
void displayArray(const int, int*);
void selectionSort(const int, int*, int*);
int linearSearch(const int, int, int*, int&);
int binarySearch(const int, int, int*, int&);

/*********************************************************************
 *                       DESCRIPTION:
 * The main function
 *
 * Performs the function calls to allocate memory for arrays to be sorted
 * and searched through. Provides visual for element location status based on
 * user defined input.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer to exit the code.
 ******************************************************************** */

int main() {
  srand(time(0));
  const int SIZE     = 105;
  int* sortedArray   = nullptr;
  int* unSortedArray = nullptr;
  int userInt        = 0;
  int iterations     = 0;
  const int EXIT     = -1;
  int linearResult   = 0;
  int binaryResult   = 0;
  createArray(SIZE, unSortedArray);
  createArray(SIZE, sortedArray);
  cout << "Here is the unsorted array!" << endl;
  displayArray(SIZE, unSortedArray);
  cout << "Here is the sorted array!" << endl;
  selectionSort(SIZE, sortedArray, unSortedArray);
  displayArray(SIZE, sortedArray);
  while (userInt != EXIT) {
    cout << "Enter an integer to search for or enter -1 to (EXIT)" << endl;
    cin >> userInt;
    if (userInt == EXIT) {
      cout << "Thank you and have a nice day!" << endl;
      return 0;
    }
    cout << "INVOKING LINEAR SEARCH FOR " << userInt << "!" << endl;
    linearResult = linearSearch(SIZE, userInt, sortedArray, iterations);
    if (linearResult == -1) {
      cout << "Element not found!" << endl;
      cout << "Number of iterations: " << iterations << endl;
    } else {
      cout << "TARGET FOUND - ELEMENT #" << linearResult << endl;
      cout << "Number of Iterations: " << iterations << endl;
    }
    cout << "INVOKING BINARY SEARCH FOR " << userInt << "!" << endl;
    binaryResult = binarySearch(SIZE, userInt, sortedArray, iterations);
    if (binaryResult == -1) {
      cout << "Element not found!" << endl;
      cout << "Number of iterations: " << iterations << endl;
    } else {
      cout << "TARGET FOUND - ELEMENT #" << binaryResult << endl;
      cout << "Number of Iterations: " << iterations << endl;
    }
  }
  return 0;
}

/*********************************************************************
 *                       DESCRIPTION:
 *
 *  Function to allocate memory to an array pointer and be filled
 *  by random integers between 1 - 100. Array size is predetermined in main
 *  function.
 *
 *  Input:
 *  - Integer for amount of elements in array pointer
 *  - An array Pointer
 *
 *  Output:
 *  N/A
 ******************************************************************** */

void createArray(const int SIZE, int*& arrayPtr) {
  const int MIN_VAL = 1;
  const int MAX_VAL = 100;
  arrayPtr          = new int[SIZE];
  for (int i = 0; i < SIZE; i++) {
    int randNum = MIN_VAL + rand() % (MAX_VAL - MIN_VAL + 1);
    arrayPtr[i] = randNum;
  }
}

/*********************************************************************
 *                       DESCRIPTION:
 *
 *  Function to display array in columns of 5 on the console.
 *
 *  Input:
 *  - Integer for the amount of elements in array pointer
 *  - Array Pointer
 *
 *  Output:
 *  N/A
 ******************************************************************** */

void displayArray(const int SIZE, int* array) {
  for (int i = 0; i < SIZE; i++) {
    if (i % 5 == 0) {
      cout << endl;
    }
    cout << left << setw(3) << array[i] << " ";
  }
  cout << endl << endl;
}

/*********************************************************************
 *                       DESCRIPTION:
 *
 *  Function to perform select sort algorithm. Function copies an array pointer
 *  to another array to preserve data. Then sorts the unsorted function in place
 *to be used throughout all other processes. The sort checks whether an element
 *is less than the index and if it is, the element in place swaps with the
 *element indexed until the array is sorted from smallest to largest value
 *integer.
 *
 *  Input:
 *  - Integer for the amount of elements in array pointer
 *  - Two array pointers, one for original unsorted array and another for
 *    the sorted array.
 *
 *  Output:
 *  N/A
 ******************************************************************** */

void selectionSort(const int SIZE, int* sortedArray, int* unSortedArray) {
  int swap;

  for (int i = 0; i < SIZE; i++) {
    sortedArray[i] = unSortedArray[i];
  }

  for (int i = 0; i < SIZE - 1; i++) {
    int min = i;
    for (int j = i + 1; j < SIZE; j++) {
      if (sortedArray[j] < sortedArray[min]) {
        min = j;
      }
    }
    if (sortedArray[min] != sortedArray[i]) {
      swap             = sortedArray[i];
      sortedArray[i]   = sortedArray[min];
      sortedArray[min] = swap;
    }
  }
}

/*********************************************************************
 *                       DESCRIPTION:
 *
 *  Function to perform the linear search algorithm. Linear search checks the
 *sorted array and verifies if the requested integer is found within the data
 *set of random integers. Will then return -1 if the integer isn't found or the
 *position of the element if the integer is within the array.  The number of
 *iterations is returned indirectly.
 *
 *  Input:
 *  - Integer for the amount of elements in array pointer
 *  - User input integer for search
 *  - Array pointer
 *  - Running count of iterations that took place to locate element from user
 *    input.
 *
 *  Output:
 *  - Integer indicating the result of -1 if not found or index position of
 *element if found
 *  - Iterations to find element
 ******************************************************************** */

int linearSearch(const int SIZE, int userInt, int* sortedArray,
                 int& iterations) {
  int results = -1;
  iterations  = 0;
  for (int i = 0; i < SIZE; i++) {
    if (sortedArray[i] == userInt) {
      return i;
    }
    iterations++;
  }
  return results;
}

/*********************************************************************
 *                       DESCRIPTION:
 *
 *  Function to perform binary search. Divides the interval in half for each
 *comparison to find user input integer.
 *
 *  Input:
 *  - Integer for the amount of elements in array pointer
 *  - User input integer for search
 *  - Array pointer
 *  - Running count of iterations that took place to locate element from user
 *    input.
 *  Output:
 *  - Integer indicating the result of -1 if not found or index position of
 *element if found
 *  - Iterations to find element
 ******************************************************************** */

int binarySearch(const int SIZE, int userInt, int* sortedArray,
                 int& iterations) {
  int first    = 0;
  int last     = SIZE - 1;
  int middle   = 0;
  int position = -1;
  bool found   = false;
  iterations   = 0;

  while (!found && first <= last) {
    middle = (first + last) / 2;
    if (sortedArray[middle] == userInt) {
      found    = true;
      position = middle;
    } else if (sortedArray[middle] > userInt) {
      last = middle - 1;
    } else {
      first = middle + 1;
    }
    iterations++;
  }
  return position;
}
