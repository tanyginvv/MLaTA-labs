//9.4. Песочные часы (6)
//Имеется коллекция из N песочных часов.Часы с номером i имеют две характеристики : Ai – максимальная длительность их работы в секундах,
//Bi – время в секундах, которое уже прошло с запуска часов.Требуется найти минимальное количество переворотов часов, чтобы все часы закончили
//  свою работу друг за другом с разницей в 1 сек.
//Ввод.Первая строка входных данных содержит единственное целое число N(1 ≤ N ≤ 20) – количество часов.Вторая строка входных данных содержит N 
// целых чисел A1, A2, ..., AN(0 ≤ Ai ≤ 104) – длительность работы часов в секундах.Третья строка входных данных содержит N целых чисел B1, B2, ..., 
// BN(0 ≤ Bi ≤ Ai ≤ 104) - время, которое прошло с запуска часов в секундах.
//Вывод.Выведите единственное целое число - минимальное количество переворотов часов, требующихся для выполнения условия.
//Если условие выполнить невозможно, то выведите - 1.Примеры
//Ввод 1         Ввод 2           Ввод 3
//3              5                4
//5 4 9          1 3 5 7 9        13 13 16 14
//3 3 6          1 3 5 7 9        9 5 6 7
//Вывод 1        Вывод 2          Вывод 3
//0               -1               1
//Выполнил: Таныгин Вадим ПС-23
//Среда разработки:Visual Studio 2022.
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

bool isArithmeticProgression(const vector<int>& arr, int start, int end) {
	for (int i = start ; i < end - 1; i++) {
		if (arr[i + 1] - arr[i] != 1) {
			return false;
		}
	}
	return true;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int N;
	fin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++) {
		fin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		fin >> B[i];
	}

	vector<int> diff(N);
	for (int i = 0; i < N; i++) {
		diff[i] = A[i] - B[i];
	}

	sort(diff.begin(), diff.end());

	if (isArithmeticProgression(diff, 0, N)) {
		fout << 0 << endl;
		return 0;
	}

	vector<int> progression(diff.begin(), diff.end());
	progression.insert(progression.end(), B.begin(), B.end());
	sort(progression.begin(), progression.end());
	progression.erase(unique(progression.begin(), progression.end()), progression.end());

	vector<int> diff1(N);

	bool found = false;
	for (int i = 0; i < progression.size() - N + 1; i++) {
		if (isArithmeticProgression(progression, i, i + N)) {
			copy(progression.begin() + i, progression.begin() + i + N, diff1.begin());
			found = true;
		}
	}
	set<int> intersection;
	set_intersection(diff1.begin(), diff1.end(), diff.begin(), diff.end(), inserter(intersection, intersection.begin()));
	if (found == false) {
		fout << -1 << endl;
	}
	else {
		fout << N - intersection.size() << endl;
	}

	return 0;
}
