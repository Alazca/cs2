#include "class.h"

/*********************************************************************
 *                       DESCRIPTION:
 * The main function
 *
 * Performs tests for the StringCS2 class.
 *
 * Pre-conditions:
 * N/A
 *
 * Post-conditions:
 * Exit.
 *
 ******************************************************************** */


int main() {
    // Test default constructor
    StringCS2 str1;
    cout << "str1 = " << str1 << endl;

    // Test string constructor
    StringCS2 str2("hello, world");
    cout << "str2 = " << str2 << endl;

    // Test integer constructor
    StringCS2 str3 = 123;
    cout << "str3 = " << str3 << endl;

    StringCS2 str4 = "cheese whizz";
    cout << "str4 = " << str4 << endl;

    // Test copy constructor
    StringCS2 str5(str4);
    cout << "str5 = " << str5 << endl;

    // Test assignment operator
    str1 = str2;
    cout << "str1 = " << str1 << endl;

    // Test consecutive assignment
    str1 = str2 = str3;
    cout << "str1 = " << str1 << endl;

    // Test equality operator
    if (str1 == str2) {
        cout << "str1 and str2 are equal" << endl;
    } else {
        cout << "str1 and str2 are not equal" << endl;
    }
    if (str1 == str3) {
        cout << "str1 and str3 are equal" << endl;
    } else {
        cout << "str1 and str3 are not equal" << endl;
    }

    // Test subscript operator
    str4[0] = 'C';
    cout << "str4 = " << str4 << endl;

    // Test length
    cout << "Length of str2 is " << str2.length() << endl;
    cout << "Length of str3 is " << str3.length() << endl;

    // Test stream operator
    cout << "str1 = " << str1 << "; str2 = " << str2 << "; str3 = " << str3 << endl;

    return 0;
}
