/*
 * project2.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: eddy_
 */


#include <iostream>
using namespace std;
#include "myString.h"
#include "bagOfWords.h"

// get one token from redirected input and return that string (alphanumeric)
char* getNextToken () {
	char* str = new char[20]; //assumes a max token size of 20
	emptyString(str, 20);

	char c;
	int i = 0;
	while (!cin.eof()) {
		cin.get(c);
		if (!cin.eof ()) {
			if ((c != '\n') && (c != ' ')) {
				if ( ((c >= 'a') && (c <= 'z')) ||
					 ((c >= 'A') && (c <= 'Z')) ||
					 ((c >= '0') && (c <= '9')) )
					str[i++] = c;
			}
			else if ((c == '\n') && (i > 0))
				return str;
			else if ((c == ' ') && (i > 0))
				return str;
		}
	}
	if (i > 0) return str;
	else return NULL;
}

int main(){
		int numStopWords;
		char* token;
		myString* tokenString;

	    //read the first number from the file that contains the number of stop words
		cin >> numStopWords;
		myString* stopWordsList = new myString[numStopWords];

		//read the stop words
		for (int i=0; i < numStopWords; i++) {
			token = getNextToken();
			stopWordsList[i] = token; //calls the overloaded = operator on myString class
		}

		//Now read a text and put them in the bagOfWords instance.
		bagOfWords* myBag = new bagOfWords ();
		token = getNextToken(); //first read the token as an array of characters
		tokenString = new myString (token);//create a myString object with the token

		while (token != NULL) {
			(*myBag).addWord(*tokenString); //add token to myBag
			token = getNextToken ();
		}

		// this should display the token and frequency;
		// note that becuase you are using binary search and insert the tokens will
		// be sorted alphabetically
		(*myBag).display ();

		(*myBag).sortFreq ();
		(*myBag).display ();
		(*myBag).sortWords();
		(*myBag).display ();
		bagOfWords* newBag = (*myBag).removeStopWords(stopWordsList, numStopWords);
		(*newBag).display();
		(*newBag).sortFreq ();
		(*newBag).display ();

		delete stopWordsList;
		delete myBag;
		delete newBag;

		return 0;
}
