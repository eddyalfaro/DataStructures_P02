/*
 * myString.h
 *
 *  Created on: Mar 1, 2021
 *      Author: eddy_
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

namespace std {

class myString {

	friend ostream& operator << (ostream& s, myString& A);

	protected:
		char* strArray;
		int size;
		void strCpy (char* A, char* B, int n);
		char* getWord();

	public:
		myString ();//default constructor
		myString(char* inpStr);//non-default constructor
		myString (myString& B);//copy constructor

		int Size();
		int compareTo(myString& B);

	    bool operator == (myString& B);
		bool operator > (myString& B);
		bool operator < (myString& B);

		void display();

		myString& operator = (myString& B);
		myString& operator = (char* B);

		~myString();
};

} /* namespace std */

#endif /* MYSTRING_H_ */
