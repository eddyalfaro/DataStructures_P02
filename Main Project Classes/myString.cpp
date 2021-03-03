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
	for (int i=0; i < n; i++) {//runs throught the array of char and places \0 as value
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

	while (inpStr[i] != '\0') {//checks the size of the input string
		i++;
	}

	size = i;//asings the found size to the actual size value
	strArray = new char[size]; // creates array of the found size
	emptyString(strArray, size+1);//empties the string from garbage values

	for (int j=0; j < size; j++){ //fills the array with the parameter string
		strArray[j] = inpStr[j];
	}
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

myString::~myString (){
	delete [] strArray;
	size = 0;
}

//getter for the array of characters that contains the string
char* myString::getWord() {
	return strArray;
}

// getter for size of myString
int myString::Size () {
	return size;
}

// overloading = operator - initialize object with an existing string
myString& myString::operator = (char* B) {
	int i = 0;

	while (B[i] != '\0') {//checks the size of the string to be input
		i++;
	}

	size = i;//asings the found size to the actual size value
	strArray = new char[size]; // creates array of the found size
	emptyString(strArray, size+1);//empties the string from garbage values

	for (int j=0; j < size; j++){ //fills the array with the parameter string
		strArray[j] = B[j];
	}

	return *this;
}

// overloading = operator - initialize object with an existing mystring object
myString& myString::operator = (myString& B) {
	delete [] strArray;
	strArray = NULL;
	size = B.size;
	strArray = new char[size];
	emptyString(strArray, size+1);
	stringCopy(B.strArray, size, strArray);
	return *this;
}

// checking if two myString objects are the same - return true or false
bool myString::operator == (myString& B) {
	if (this->size != B.size){
		return false;
	}

	int count = 0;
	for (int i = 0; i < size; i++){
		if (this->strArray[i] == B.strArray[i]){
			count++;
		}
	}

	return (count == size);
}

// comparison of myString A if less than myString B - return true or false
bool myString::operator < (myString& B) {
	int minSize = this->size;

	if (B.size < minSize){
		minSize = B.size;
	}


	for (int i = 0; i < minSize ; i++){//checking word for word
		int diff = this->strArray[i] - B.strArray[i]; //checking the difference between the asccii values
		if (diff > 0){//exits the loop as soon as it finds a positive difference
			return false;
		} else if (diff < 0){//if no positive difference is found before a negative difference the value returns true
			return true;
		}
	}

	return (this->size < B.size);// if non of the return statements inside works, the shortest word goes first
}

// comparison of myString A if greater than myString B - return true or false
bool myString::operator > (myString& B) {
	return !(*this < B || *this == B);//returns true if it is neither greater or equals
}

int myString::compareTo(myString& B){//

	if (*this == B){
		return 0;
	} else if (*this < B){
		return -1;
	} else {
		return 1;
	}

}

void myString::display(){ // displays the value of the estring in the output stream;
	for (int i = 0; i < size; i ++){
		cout << strArray[i];
	}
}

} /* namespace std */
