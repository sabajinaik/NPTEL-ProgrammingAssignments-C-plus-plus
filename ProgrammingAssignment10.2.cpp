/*You are to write a program that manages a dictionary that stores English language words and for
each word, what part of speech (POS) it is. As you might remember, noun, verb, adjective, ... are
POSs. For example, the dictionary might have the pairs (eat, verb), (pen, noun), (wise, adjective)
in it. Initially, the dictionary is empty. You can add words into the dictionary or given a word,
you can lookup its meaning. There are 4 commands: ADD, LOOKUP, ALL, END. Your program should read
commands from the keyboard and perform the relevant action until the END command is received. Here
are the descriptions of the commands

ADD w p : In this w, p are single words, i.e. you can read them using cin >>. The first argument w
is the word to be stored, and the second argument p is its part of speech. Do not add the word again
if it already exists in the dictionary

LOOKUP w : In this the argument w is a word. The program must lookup w in the dictionary and print
its POS. If the word does not exist in the dictionary print the string “OOV”

ALL p : This should print all words in the dictionary whose POS is p.
The format of printing should be: word1 word2 … wordn , each word is followed by a space (including
the last word) and the line is terminated by a newline(using endl or \n). Note that these words must
be in lexicographic order.

END : The program should terminate.
You should use a map to store the pairs of strings. All words to be stored will be in lower case
*/

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
//#define main_program int main()
using namespace std;
class DictionaryHandler {
	map<string, string> wordDictionary;
public:
	void pushDataIntoMap() {
		bool duplicate = false;
		string dataWord, dataPOS;
		cin >> dataWord >> dataPOS;
		for (map<string, string>::iterator it = wordDictionary.begin(); it != wordDictionary.end(); ++it) if (it->first == dataWord) {
			duplicate = true;
			break;
		}
		if (duplicate == false) {
			wordDictionary[dataWord] = dataPOS;
		}
	}

	void displayAllbyPOS() {
		string inputPOS;
		cin >> inputPOS;
		for (map<string, string>::iterator it = wordDictionary.begin(); it != wordDictionary.end(); ++it) if (it->second == inputPOS) cout << it->first << " ";
		cout << endl;
	}

	void lookupByWord() {
		bool found = false;
		string dataWord;
		cin >> dataWord;
		for (map<string, string>::iterator it = wordDictionary.begin(); it != wordDictionary.end(); ++it) {
			if (it->first == dataWord) {
				found = true;
				cout << it->second;
			}
		}
		if (found == false) cout << "OOV";
		cout << endl;
	}
};


int main() {
	string dataOperation;
	DictionaryHandler dictionaryHandler;
	while (true) {
		cin >> dataOperation;
		if (dataOperation == "END") break;
		else if (dataOperation == "LOOKUP") dictionaryHandler.lookupByWord();
		else if (dataOperation == "ALL") dictionaryHandler.displayAllbyPOS();
		else if (dataOperation == "ADD") dictionaryHandler.pushDataIntoMap();
	}
}