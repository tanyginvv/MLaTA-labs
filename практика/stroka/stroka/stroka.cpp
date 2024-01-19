#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::string findSubstring(const std::string& str) {
	std::string result;
	int maxUniqueCount = 0;

	std::unordered_map<char, int> charCount;

	int start = 0;
	int end = 0;

	while (end < str.length()) {
		char currentChar = str[end];
		charCount[currentChar]++;

		while (charCount[currentChar] > 1) {
			charCount[str[start]]--;
			start++;
		}

		int uniqueCount = end - start + 1;

		if (uniqueCount > maxUniqueCount) {
			maxUniqueCount = uniqueCount;
			result = str.substr(start, uniqueCount);
		}
		else if (uniqueCount == maxUniqueCount) {
			result = std::min(result, str.substr(start, uniqueCount));
		}

		end++;
	}

	return result;
}

int main() {
	std::ifstream inputFile("INPUT9.TXT");
	std::ofstream outputFile("OUTPUT.TXT");

	int N;
	std::string inputString;

	if (inputFile.is_open()) {
		inputFile >> N;
		inputFile >> inputString;
		inputFile.close();

		std::string substring = findSubstring(inputString);

		outputFile << substring;
		outputFile.close();
	}

	return 0;
}
