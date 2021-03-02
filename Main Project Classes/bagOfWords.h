/*
 * bagOfWords.h
 *
 *  Created on: Mar 1, 2021
 *      Author: eddy_
 */

#ifndef BAGOFWORDS_H_
#define BAGOFWORDS_H_
#include "myString.h"

namespace std {

class bagOfWords {
	private:
		int binarySearchAndInsert (myString& W);
		int binarySearch(myString& word, int lowVal, int highVal);//searches for a word in a sorted array returning the index if found and -1 if not found;
		int search(myString& word); //searches for a word in a non-sorted array returning the index if found and -1 if not found;

		void insert(int index, myString& newWord);

	protected:
		myString* _words;//stores the Strings readed from imput
		int* _frequencies;//stores the frequencies of the words. It is sincronizzed by index with the words
		int _size;//stores the number of words that are added in the array

		int get_size();
		int* get_Freq();
		void setSize(int i);

	public:
		bagOfWords ();
		bagOfWords (int numOfWords);
		myString* get_Words();
		void addWord (myString& W);//insert word w into the array _words - keep it sorted alphabetically
		void sortFreq(); //sort words array based on frequency
		void sortWords(); //sort words array alphabetically
		void display(); //print word followed by a colon followed by a single space and frequencuy
		bagOfWords* removeStopWords(myString* stopWords, int numStopWords); //remove all the words in the array
									//stopWords from _words array
		~bagOfWords();

};

} /* namespace std */

#endif /* BAGOFWORDS_H_ */
