/*
 * bagOfWords.cpp
 *
 *  Created on: Mar 1, 2021
 *      Author: eddy_
 */

#include "bagOfWords.h"

namespace std {

// default constructor - initializes with no words
bagOfWords::bagOfWords()
{
	_size = 0;
	_words = new myString[0];
	_frequencies = new int[0];
}

// non default constructor - initializes with a known number of words
bagOfWords::bagOfWords (int numOfWords)
{
	_size = numOfWords;
	_words = new myString[numOfWords];
	_frequencies = new int[numOfWords];
}

bagOfWords::~bagOfWords (){

}

myString* bagOfWords::get_Words()
{
	return _words;
}

int* bagOfWords::get_Freq()
{
	return _frequencies;
}

int bagOfWords::get_size()
{
	return _size;
}

void bagOfWords::setSize(int i)
{
	_size = i;
}

// print the bag of words in dictionary format
void bagOfWords::display()
{

	// TODO

}

// sort the _words and _frequencies based on frequencies
void bagOfWords::sortFreq()
{
	// TODO
}

// sort the _words and _frequencies, alphabetically
void bagOfWords::sortWords()
{
	// TODO
}

bagOfWords* bagOfWords::removeStopWords(myString* stopWords, int numStopWords)
{

	// TODO

	return NULL;
}

// to search for a given word in _words - returns 0 if not found, 1 if found
int bagOfWords::binarySearchAndInsert (myString& wordToFind)
{

	// TODO

	return 0;
}

// method to add words to the bagOfWords object
void bagOfWords::addWord(myString & newWord)
{
	// TODO
}

} /* namespace std */
