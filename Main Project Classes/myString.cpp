/*
 * myString.cpp
 *
 *  Created on: Mar 1, 2021
 *      Author: eddy_
 */

#include "myString.h"

namespace std {

// used to empty a given string A of length n
void emptyString (char* A, int n) {
	for (int i=0; i < n; i++) {
		A[i] = '\0';
	}
}

// copy a string A to B of length n
void stringCopy (char* A, int n, char* B) {
	for (int i=0; i < n; i++) {
		B[i] = A[i];
	}
}

// return the length of a given string A
int stringLength (char* A) {
	int size = 0;
	while (A[size] != '\0') size++;
	return size; //size is the last index position
}

// outputs a given string A
ostream& operator << (ostream& s, myString& A) {
	s << A.strArray;
	return s;
}

// default constructor - initializes with a NULL as the first character
myString::myString () {
	size = 0;
	strArray = new char[1];
	strArray[0] = '\0';
}

// non default constructor - initialize object with an existing string
myString::myString (char* inpStr) {
	int i = 0;
	while (inpStr[i] != '\0')
		i++;
	size = i;
	strArray = new char[size];
	emptyString(strArray, size+1);
	for (int j=0; j < size; j++)
		strArray[j] = inpStr[j];
}

// non default constructor - initialize object with an existing mystring object
myString::myString (myString& B) {
	delete [] strArray;
	strArray = NULL;
	size = B.size;
	strArray = new char[size];
	emptyString(strArray, size+1);
	stringCopy(B.strArray, size, strArray);
}

char* myString::getWord() {
	return strArray;
}

// getter for size of myString
int myString::Size () {
	return size;
}

// overloading = operator - initialize object with an existing string
myString& myString::operator = (char* B) {

	// TODO

	return NULL;
}

// overloading = operator - initialize object with an existing mystring object
myString& myString::operator = (myString& B) {

	// TODO

	return NULL;
}

// checking if two myString objects are the same - return true or false
bool myString::operator == (myString& B) {

	// TODO

	return false;
}

// comparison of myString A if less than myString B - return true or false
bool myString::operator < (myString& B) {

	return false;
}

// comparison of myString A if greater than myString B - return true or false
bool myString::operator > (myString& B) {

	// TODO

	return false;
}


} /* namespace std */
