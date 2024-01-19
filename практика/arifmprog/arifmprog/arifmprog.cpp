#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ifstream fin("in5.txt");
	ofstream fout("output5.txt");
	int L;
	fin >> L;
	for (int i = 0; i < L; i++) {
		int N;
		fin >> N;
		vector<int> a(N);
		for (int j = 0; j < N; j++) {
			fin >> a[j];
		}
		sort(a.begin(), a.end());
		if (N <= 2) {
			fout << "Yes" << endl;
		}
		else {
			int d = a[1] - a[0];
			bool ok = true;
			for (int j = 2; j < N; j++) {
				if (a[j] - a[j - 1] != d) {
					ok = false;
					break;
				}
			}
			if (ok) {
				fout << "Yes" << endl;
			}
			else {
				fout << "No" << endl;
			}
		}
	}
	return 0;
}