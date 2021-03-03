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

		void insert(int index, myString& newWord);//inserts the given word at the given index in _words array
		void incrementSize();//increments the number of elements of _words array by one

		template <typename T, typename V>
		void merge(T* array, int from, int to, V* syncArray); //helper method to merge the sorted spitted array from sort

		void shiftDownFrom(int index);//moves everything down by one index from the given index
									// i; i+1; index; .... ; (_size -1)
									// i; i+1; i+2; index; ..... ; (_size)
		void shiftUpFrom(int index);//shifts everything up by one index from one after the given index
									// i; i+1; index; .... ; (_size -1)
									// i; i+1; i+3; ..... ; (_size - 2)

	protected:
		myString* _words;//stores the Strings readed from imput
		int* _frequencies;//stores the frequencies of the words. It is sincronizzed by index with the words
		int _size;//stores the number of words that are added in the array

		int get_size();
		void setSize(int i);

	public:
		bagOfWords ();
		bagOfWords (int numOfWords);
		~bagOfWords();

		myString* get_Words();
		int* get_Freq();

		void addWord (myString& W);//insert word w into the array _words - keep it sorted alphabetically
		void sortFreq(); //sort words array based on frequency
		void sortWords(); //sort words array alphabetically
		void display(); //print word followed by a colon followed by a single space and frequencuy

		template <typename T, typename V>
		void mergeSort(T& arraytoSort, int from, int to, V& sincArray); //sorts an array of data type T, with to being inclusive

		bagOfWords* removeStopWords(myString* stopWords, int numStopWords); //remove all the words in the array
									//stopWords from _words array
};

} /* namespace std */

#endif /* BAGOFWORDS_H_ */
