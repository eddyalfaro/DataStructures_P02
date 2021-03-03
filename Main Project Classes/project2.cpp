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


// used to empty a given string A of length n
void emptyString (char* A, int n) {
	for (int i=0; i < n; i++) {//runs throught the array of char and places \0 as value
		A[i] = '\0';
	}
}

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
		//cout << "Reading " << numStopWords << " words" << endl;

		//read the stop words
		for (int i=0; i < numStopWords; i++) {
			token = getNextToken();
			//cout << *token << endl;
			stopWordsList[i] = token; //calls the overloaded = operator on myString class

			/*if (i > 0){
				cout << "Comparing <" << stopWordsList[i - 1] << "> with <" << stopWordsList[i];
				cout << "> resulting value: " << (stopWordsList[i]).compareTo(stopWordsList[i - 1]) << endl;
			}*/
		}
		cout << "Number of Stop words: " << numStopWords << endl << endl;

		//Now read a text and put them in the bagOfWords instance.
		bagOfWords* myBag = new bagOfWords();
		token = getNextToken(); //first read the token as an array of characters
		tokenString = new myString (token);//create a myString object with the token
		//cout << "Adding words from text" << endl << endl;

		while (token != NULL) {
			tokenString = new myString(token);
			(*myBag).addWord(*tokenString); //add token to myBag
			token = getNextToken();
			//cout << endl;
		}

		//cout << "WHILE LOOP EXITED" << endl;
		cout << "Input display:" << endl;
		// this should display the token and frequency;
		// note that becuase you are using binary search and insert the tokens will
		// be sorted alphabetically
		(*myBag).display ();

		cout << endl << "myBag - Sorted based on frequency:" << endl;

		(*myBag).sortFreq ();
		(*myBag).display ();

		cout << endl << "myBag - Sorted alphabetically:" << endl;
		(*myBag).sortWords();
		(*myBag).display ();

/*		bagOfWords* newBag = (*myBag).removeStopWords(stopWordsList, numStopWords);
		(*newBag).display();
		(*newBag).sortFreq ();
		(*newBag).display ();

		delete stopWordsList;
		delete myBag;
		delete newBag;
*/
		return 0;
}
