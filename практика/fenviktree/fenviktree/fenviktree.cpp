#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> B;
int N;

int Rsq(int k) {
	int res = 0;
	while (k >= 0) {
		res += B[k] ;
		k = (k & (k + 1 )) - 1;
	}
	return res;
}

void Add(int k, int d) {
	while (k < N) {
		B[k] += d;
		k = k | (k + 1);
	}
}

void Update(int k, int v) {
	int diff = v - Rsq(k) + Rsq(k - 1);
	Add(k, diff);
}

int main() {
	ifstream fin("input.txt");
	int n;
	fin >> n;

	N = n;
	vector<int> A(n);
	B.resize(n, 0);

	for (int i = 0; i < n; i++) {
		fin >> A[i];
		Add(i, A[i]);
	}

	string choice;
	bool working = true;
	while (working) {
		while (working) {
			cout << "\n1 Out\n";
			cout << "2 Rsq\n";
			cout << "3 Add\n";
			cout << "4 Update\n";
			cout << "5 Exit\n";
			cin >> choice;

			if (choice == "Out") {
				for (int num : A) {
					cout << num << " ";
				}
			}
			else if (choice == "Rsq") {
				int startIdx, endIdx;
				cin >> startIdx >> endIdx;
				int sum = Rsq(endIdx) - Rsq(startIdx - 1);
				cout << sum;
			}
			else if (choice == "Add") {
				int idx, value;
				cin >> idx >> value;
				Add(idx, value);
				A[idx] += value;
			}
			else if (choice == "Update") {
				int idx, value;
				cin >> idx >> value;
				Update(idx, value);
				A[idx] = value;
			}
			else if (choice == "Exit") {
				working = false;
				break;
			}
		}

		return 0;
	}
}