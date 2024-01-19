#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int a[1001][1001];

int main() {
	unsigned int start_time = clock();
	fstream fin("input9.txt");
	ofstream fout("output.txt");
	int n, m, r, c, t;
	fin >> n >> m;
	c = 0;
	t = m;
	while (t > 0) {
		fin >> r >> c;
		if (a[r][c] == 0) {
			t--;
			a[r][c] = 1;
		}
	}
	while (m < n * n) {
		t++;
		for (r = 1; r <= n; r++) {
			for (c = 1; c <= n; c++) {
				if (a[r][c] == t) {
					if (r > 1 && a[r - 1][c] == 0) {
						a[r - 1][c] = t + 1;
						m++;
					}
					if (r < n && a[r + 1][c] == 0) {
						a[r + 1][c] = t + 1;
						m++;
					}
					if (c > 1 && a[r][c - 1] == 0) {
						a[r][c - 1] = t + 1;
						m++;
					}
					if (c < n && a[r][c + 1] == 0) {
						a[r][c + 1] = t + 1;
						m++;
					}
				}
			}
		}
	}
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time;
	
	fout << t << endl;
	cout << search_time;
	return 0;
}