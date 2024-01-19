#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int main() {
	ifstream input("INPUT7.TXT");
	ofstream output("OUTPUT.TXT");
	string word;
	input >> word;
	vector<string> dictionary;
	map<char, int> word_letters_count;
	for (char letter : word) {
		word_letters_count[letter]++;
	}
	string dict_word;
	while (input >> dict_word) {
		bool can_build_word = true;
		map<char, int> dict_word_letters_count;
		for (char letter : dict_word) {
			dict_word_letters_count[letter]++;
			if (dict_word_letters_count[letter] > word_letters_count[letter]) {
				can_build_word = false;
				break;
			}
		}
		if (can_build_word) {
			dictionary.push_back(dict_word);
		}
	}
	int score = 0;
	map<int, vector < string>> found_words_alpha;
	for (string dict_word : dictionary) {
		map<char, int> letters_left = word_letters_count;
		bool can_build_word = true;
		for (char letter : dict_word) {
			if (letters_left[letter] > 0) {
				letters_left[letter]--;
			}
			else {
				can_build_word = false;
				break;
			}
		}
		if (can_build_word) {
			score += dict_word.length();
			found_words_alpha[dict_word.length()].push_back(dict_word);
		}
	}

	output << score << endl;

	vector<int> word_lengths;
	for (auto it : found_words_alpha) {
		word_lengths.push_back(it.first);
	}
	sort(word_lengths.begin(), word_lengths.end(), greater<int>());

	for (int word_len : word_lengths) {
		vector<string> words = found_words_alpha[word_len];
		sort(words.begin(), words.end());
		for (string word : words) {
			output << word << endl;
		}
	}
	return 0;
}
