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

	protected:
		myString* _words;
		int* _frequencies;
		int _size;

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