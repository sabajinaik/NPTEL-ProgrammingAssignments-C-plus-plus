/*There is a boy named Ali. He is a very curious child. His friend Shreya who likes to play with him read
him a set of words and asked to find the maximum size subset of anagrams of the given set words. He,  like
always,  got very excited and now wants you to solve the question for him.

Note: An anagram is a word or phrase formed by rearranging the letters of a different word. ( for us, the
words are just strings they need not have any meaning )

More specifically,

Given an n sized set S of lowercase strings (only a-z characters allowed) ( all size 5 in length ) find
the size k of the largest subset of anagrams. Since it is a set, the given input won't have duplicates.

{ s1, s2, .. sk }  such that si, sj are anagrams and belong to S for all  1<= i, j <= k.

Input:
n (size of the set)
s1
s2
..
sn

Output:
k
where k is the max size anagram set.

1<= n <= 100
Most of the code is written down for you.
You have to write a function:
int max_anagram_subset(char string_set[][5], int n)
which takes the array (set) and n as input and returns k.

Preferably create a function:
bool are_anagrams(char s1[5], char s2[5])

which returns whether 2 strings are anagrams or not and use it within the former function.
*/

#include <iostream>
#define repeat(x) for(int _iterator_i = 0; _iterator_i<x;_iterator_i++)
#define main_program int main()
#include <cmath>
using namespace std;
bool are_anagrams(char s1[5], char s2[5]) {
	bool final_flag = true;
	for (int i = 0; i < 5; i++) {
		bool return_flag = false;
		for (int j = 0; j < 5; j++) {
			if (s1[i] == s2[j]) {
				s2[j] = ' ';
				return_flag = true;
				break;
			}
		}
		final_flag = final_flag && return_flag;
	}
	return final_flag;
}

int max_anagram_subset(char string_set[][5], int n) {
	int sum = 1;
	for (int i = 1; i < n; i++) {
		if (are_anagrams(string_set[0], string_set[i])) sum++;
	}
	return sum;
}
main_program{
	int n; cin >> n;
	char string_set[n][5];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			cin >> string_set[i][j];
	cout << max_anagram_subset(string_set, n) << endl;
}