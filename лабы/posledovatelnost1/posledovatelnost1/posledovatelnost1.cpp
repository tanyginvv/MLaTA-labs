//10.1.Последовательность 1 (6)
//В последовательности чисел a1, a2, a3, ... задан первый член, а остальные вычисляются по формуле ai = (ai - 1)2 mod M + 1. Найти N - й член последовательности.
//Ограничения: 1 ≤ M ≤ 10000, 2 ≤ N ≤ 1018, 0 ≤ a1 ≤ M.
//Ввод из файла INPUT.TXT.В первой строке находятся числа M, N и a1, разделённые пробелом.
//Вывод в файл OUTPUT.TXT.Вывести одно число - aN.
//Примеры
//Ввод 1      Ввод 2
//10000 3 4   7777 2000000000 0
//Вывод 1     Вывод 2
//290         3834
//Подсказка.Сколько разных чисел может быть в последовательности ? Обязан ли в ней присутствовать цикл ? Обязательно ли цикл начинается с первого элемента ?
//Выполнил: Таныгин Вадим ПС-23
//Среда выполнения: Visual Studio 2022.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long findNthSequanceNumber(long long M, long long N, long long a1) {
	vector<long long> cache(M, -1);
	cache[a1] = 0;

	long long currentSeqNumb = a1;
	for (long long i = 1; i < N; i++) {
		currentSeqNumb = (currentSeqNumb * currentSeqNumb) % M + 1;
		if (cache[currentSeqNumb] != -1) {
			long long cycleStartIndex = cache[currentSeqNumb];
			long long cycleLength = i - cycleStartIndex;
			long long remainingSteps = (N - i - 1) % cycleLength;
			for (long long j = 0; j < remainingSteps; j++) {
				currentSeqNumb = (currentSeqNumb * currentSeqNumb) % M + 1;
			}
			break;
		}
		cache[currentSeqNumb] = i;
	}

	return currentSeqNumb;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	long long M, N, a1;
	fin >> M >> N >> a1;

	long long result = findNthSequanceNumber(M, N, a1);

	fout << result << endl;

	fin.close();
	fout.close();

	return 0;
}