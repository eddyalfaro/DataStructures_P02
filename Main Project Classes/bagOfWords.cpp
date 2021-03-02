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
	delete [] _words;
	delete [] _frequencies;
	_size = 0;
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
	cout << "Bag of Words: " << _size << endl;
	for (int i = 0 ; i < _size; i++){
		cout << _words[i] << ": " << _frequencies[i] << endl;
	}
}

// sort the _words and _frequencies based on frequencies
void bagOfWords::sortFreq()
{
	// TODO
}

template <typename T>
void bagOfWords::mergeSort(T& array, int from, int to){


}

template <typename T>
void bagOfWords::merge(T& array, int from, int to){

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
	int indexFound = binarySearch(wordToFind, 0, _size - 1);
	//cout << "index = " << indexFound << ". ";
	//cout << "size = " << _size << endl;

	if (indexFound == _size){//word found to be placed at the end of the array
		incrementSize();
		//cout << "word found to be placed at the end of the array" << endl;

		_words[_size] = wordToFind;

		//cout << "<" << _words[_size] << "> is a new word" << endl;

		_frequencies[_size] = 1;
		_size++;

		//cout << "<" << _words[indexFound] << "> first appereance, frequency of " << _frequencies[indexFound] << endl;
		return 1;
	}

	if (_words[indexFound] == wordToFind){//word found within the array
		_frequencies[indexFound] += 1;
		//cout << "<" << _words[indexFound] << "> already present within array" << endl;
		//cout << "<" << _words[indexFound] << "> has a frequency of " << _frequencies[indexFound] << endl;
		return 1;
	}else {//word to be inserted at a specific location within array
		//cout << "<" << _words[indexFound] << "> needs to be inserted in array" << endl;
		insert(indexFound, wordToFind);
		return 1;
	}

	return 0;
}

// method to add words to the bagOfWords object
void bagOfWords::addWord(myString& newWord){

	//cout << "Adding <" << newWord << ">" << endl;
	if (_size == 0){//add the first Word
		incrementSize();
		_words[_size] = newWord;
		_frequencies[_size++] = 1;

		//cout << _words[0] << " has been added" << endl;
		//cout << _words[0] << " has a frequency of " << _frequencies[0] << endl;
	}else {//find if the word has already been added or not
		binarySearchAndInsert(newWord);
	}

//	for (int i = 0; i < (_size); i++){
//			cout << "word N. " << i << ": <" << _words[i];
//			cout << ">. With frequency " << _frequencies[i] << endl;
//	}
}

void bagOfWords::incrementSize(){

	//cout << "increasing array size " << endl;
	int newSize =  _size + 1;
	myString* temp = new myString[newSize];
	int* frqTemp = new int[newSize];

	for (int i = 0; i < (_size); i++){
		temp[i] = _words[i];
		frqTemp[i] = _frequencies[i];
	}

	_words = new myString[newSize];
	_frequencies = new int[newSize];

	_words = temp;
	_frequencies = frqTemp;

}

void bagOfWords::shiftDownFrom(int index){

	for (int i = _size; i > index; i--){
		_words[i] = _words[i-1];
		_frequencies[i] = _frequencies[i-1];
	}

}

void bagOfWords::shiftUpFrom(int index){

	for (int i = index; i < (_size - 1); i++){
		_words[i] = _words[i + 1];
		_frequencies[i] = _frequencies[i + 1];
	}

}

void bagOfWords::insert(int index, myString& newWord){//inserts word and shift elements to the right//down
	//cout << "inserting <" << newWord << ">" << endl;
	incrementSize();
	shiftDownFrom(index);
	_words[index] = newWord;
	_frequencies[index] = 1;
	_size++;
}

int bagOfWords::binarySearch(myString& word, int lowVal, int highVal){
	int midVal;        // Midpoint of low and high values
	int itemPos;       // Position where item found, -1 if not found
	int rangeSize;     // Remaining range of values to search for match

	//cout << "<" << word << "> finding within range [" << lowVal << ", " << highVal << ")" << endl;
	rangeSize = (highVal - lowVal) + 1;
	midVal = (highVal + lowVal) / 2;

	if (word == _words[midVal]) {// Base case 1: item found at midVal position
		//cout << "<" << word << "> found word at index: ";
		itemPos = midVal;
	} else if (rangeSize == 1) {// Base case 2: match not found, returns the position at which the word must be inserted
		//cout << "Word not found. Last word searched: <" << _words[midVal] << ">" << endl;
		//cout << "New word must be inserted in position: ";

		if (_words[midVal] < word){
			itemPos = midVal + 1;
		} else {
			itemPos = midVal;
		}
	} else { // Recursive case: search lower or upper half
		if (word.compareTo(_words[midVal]) < 0) { // Search lower half, recursive call
			//cout << "Searching lower half." << endl;
			itemPos = binarySearch(word, lowVal, midVal);
		}else { // Search upper half, recursive call
			//cout << "Searching upper half." << endl;
			itemPos = binarySearch(word, midVal + 1, highVal);
		}
	}

	//cout << itemPos << endl;
	return itemPos;
}

int bagOfWords::search(myString& word){
	for (int i = 0; i < _size; i++){

		if (_words[i].compareTo(word) == 0){
			return i;
		}
	}

	return -1;
}

} /* namespace std */
