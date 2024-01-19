//13.1.Алгоритм Рабина - Карпа(6)
//Требуется найти все вхождения образца в текстовом файле методом Рабина - Карпа.В файле нет переноса слов.
// Образец может включать пробелы и переходить с одной строки файла на другую.Конец строки файла может интерпретироваться
// как пробел.Результаты поиска не должны зависеть от регистра букв, то есть каждая буква в образце и файле может быть как
// строчной, так  и прописной.
//Ввод из файла INPUT.TXT.Первая строка файла является образцом и имеет длину от 1 до 255. Вторая строка задает имя текстового файла.
//Вывод в файл OUTPUT.TXT.Вывести в каждой строке через пробел последовательность номеров строк и позиций в строке, начиная с которых
//образец входит в текст.Нумерация строк и позиций в строке начинается с 1. Если вхождений нет, вывести No.
//Пример
//Ввод
//Мама мыла раму
//Bukvar.txt
//Вывод
//1 1
//1 23
//Пояснение.Файл Bukvar.txt состоит из следующих двух строк :
//Мама мыла раму вчера, мама
//мыла раму сегодня.
//Выполнил:Таныгин Вадим ПС-23
//Среда разработки:Visual Studio 2022.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

const int p = 31;
const int MOD = 256;

long long hash_string(const string& s) {
	int hash = 0;
	int p_pow = 1;
	int m = s.length();

	for (int i = 0; i < m; i++) {
		hash = (hash + (s[i] - 'a' + 1) * p_pow) % MOD;
		p_pow = (p_pow * p) % MOD;
	}

	return hash;
}

vector < pair<int, int>> findOccurrences(const string& pattern, const string& filename) {
	setlocale(LC_ALL, "Russian");
	ifstream inputFile(filename);
	string line;
	vector < pair<int, int>> occurrences;
	int patternLength = pattern.length();
	string lowerPattern;
	for (char c : pattern) {
		lowerPattern += tolower(c);
	}

	string text;
	vector<int> lineLengths;
	int lineNum = 1;
	int posInLine = 1;
	while (getline(inputFile, line)) {
		string lowerLine;
		for (char c : line) {
			lowerLine += tolower(c);
		}

		text += lowerLine + " ";
		lineLengths.push_back(line.length());
		lineNum++;
	}

	inputFile.close();

	int textLength = text.length();
	long long patternHash = hash_string(lowerPattern);

	int pos = 0;
	for (int i = 0; i <= textLength - patternLength; i++) {
		string substring = text.substr(i, patternLength);
		long long substringHash = hash_string(substring);

		if (substringHash == patternHash && substring == lowerPattern) {
			int linePos = 0;
			int lineNumber = 1;
			for (int j = 0; j < lineLengths.size(); j++) {
				if (pos + patternLength <= linePos + lineLengths[j]) {
					occurrences.push_back({ lineNumber, posInLine });
					break;
				}
				linePos += lineLengths[j] + 1;
			}
		}

		if (text[i] == ' ') {
			pos++;
		}
		posInLine++;
	}
	for (auto& occurrence : occurrences) {
		int lineIndex = 0;
		int lineLength = lineLengths[lineIndex];

		while (occurrence.second > lineLength) {
			occurrence.second -= lineLength + 1;
			occurrence.first++;
			lineIndex++;
			lineLength = lineLengths[lineIndex];
		}
	}

	return occurrences;
}

int main() {
	string pattern, filename;

	ifstream inputFile("INPUT.TXT");
	getline(inputFile, pattern);
	getline(inputFile, filename);
	inputFile.close();

	vector < pair<int, int>> occurrences = findOccurrences(pattern, filename);

	ofstream outputFile("OUTPUT.TXT");
	if (occurrences.empty()) {
		outputFile << "No" << endl;
	}
	else {
		for (const auto& occurrence : occurrences) {
			outputFile << occurrence.first << " " << occurrence.second << endl;
		}
	}
	outputFile.close();

	return 0;
}