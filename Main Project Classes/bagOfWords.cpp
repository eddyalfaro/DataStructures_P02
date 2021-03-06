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
	mergeSort(_frequencies, 0, (_size - 1), _words);
}

template <typename T, typename V>
void bagOfWords::mergeSort(T& array, int from, int to, V& syncArray){

	int highVal, lowVal, midVal; //array identifiers for locations to sort and midpoit
	int rangeSize; //identifies how many values are within the range

	highVal = to;
	lowVal = from;
	midVal = (to + from)/2;

	rangeSize = (to - from) + 1;

	if (rangeSize == 1){// CASE 1: only one value to be sorted
		//cout << "only one value left, index [" << midVal << "] with element member <" << array[midVal] << ">" << endl;
		return;
	} else { // Recurring case. splits the array in two until reaches case one then returns and sorts the upper and lower halfs
		mergeSort(array, lowVal, midVal, syncArray);//sorts upper half
		mergeSort(array, midVal + 1, highVal, syncArray);//sorts lower half
		merge(array, lowVal, highVal, syncArray);//merges the sorted lower and upper halfs
	}

}

template <typename T, typename V>
void bagOfWords::merge(T* array, int from, int to, V* syncArray){
	int upperLow, upperHigh;
	int lowerLow, lowerHigh;
	int numOfElements;

	upperLow = from;
	upperHigh = (from + to)/2;

	lowerLow = upperHigh + 1;
	lowerHigh = to;

	numOfElements = (to - from) + 1;

	T* temp = new T[numOfElements];
	V* tempSync = new V[numOfElements];

	int k = 0;//counter for total elements added;
	int i = upperLow;//counter for elements in the upper half
	int j = lowerLow;//counter for elements in the lower half

	while ((i <= upperHigh) && (j <= lowerHigh)){//merging arrays: when both counters are within their ranges

			if (array[i] > array[j]){//checks for the smallest value between the upper and loweer half
				//cout << " Merging <" << (array[i]) << "> at index position " << i << endl;
				temp[k] = (array[j]); //add the value in the upper section
				tempSync[k++] = (syncArray[j]); //add the value sync to the array
				j++;
			} else {//checks for the smallest value between the upper and loweer half
				//cout << " Merging <" << (array[j]) << "> at index position " << j << endl;
				temp[k] = (array[i]);//add the value in the lower section
				tempSync[k++] = (syncArray[i]);//add the value sync to the array
				i++;
			}

	}

	while(i <= upperHigh){//if values in the lower secition have already been depleated
			temp[k] = (array[i]); //add the value in the uppwe section
			tempSync[k++] = (syncArray[i]);
			i++;
	}

	while(j <= lowerHigh){//if the values in the upper section have already been depleated
		temp[k] = (array[j]); //add the values in the lower section
		tempSync[k++] = (syncArray[j]);
		j++;
	}

	//cout << "MERGE METHOD - Merged Elements: " << numOfElements << endl;
	for (int i = from; i < (to + 1); i++){
		array[i] = temp[i - from];
		syncArray[i] = tempSync[i - from];
		//cout << "{index = " << (i) << ", element = " << array[i] << '}' << '\t';
	}
	//cout << endl << endl;

	delete [] temp;
	delete [] tempSync;
}

// sort the _words and _frequencies, alphabetically
void bagOfWords::sortWords()
{
	mergeSort(_words, 0, (_size -1), _frequencies);
}

bagOfWords* bagOfWords::removeStopWords(myString* stopWords, int numStopWords)
{
	int index = 0;
	int remotions = 0;
	sortWords();
	//cout << "removing words from list, Checking " << numStopWords << " of words" << endl;
	for (int i = 0; i < numStopWords; i++){
		//cout << "searching for <" << stopWords[i] << "> within bag." << endl;
		index = binarySearch(stopWords[i], 0, _size -1);
		//cout << "index found to be [" << index << "]" << endl;
		//cout << "word at [" << index << "] is <" << _words[index] << ">" << endl;
		if (_words[index] == stopWords[i]){
			//cout << "word at index [" << index << "] is <" << _words[index] << ">, removing..." << endl;
			shiftUpFrom(index);
			remotions++;
			//cout << "word removed, new size: " << _size << ". Number of words removed: " << remotions << endl;
		}
		//cout << endl;
	}

	//cout << endl;
	return this;
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

	_size--;

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
