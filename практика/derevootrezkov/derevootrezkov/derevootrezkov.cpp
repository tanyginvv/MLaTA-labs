#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> A; 
vector<int> T; 
vector<int> Add; 

void Build(int i, int L, int R) {
	if (L == R) {
		T[i] = A[L];
	}
	else {
		int m = (L + R) / 2;
		Build(2 * i, L, m);
		Build(2 * i + 1, m + 1, R);
		T[i] = max(T[2 * i], T[2 * i + 1]);
	}
}


int Rmq(int L, int R, int i, int Tl, int Tr) {
	if (L == Tl && R == Tr) {
		return T[i];
	}
	else {
		int m = (Tl + Tr) / 2;
		if (R <= m) {
			return Rmq(L, R, 2 * i, Tl, m);
		}
		else if (L > m) {
			return Rmq(L, R, 2 * i + 1, m + 1, Tr);
		}
		else {
			return max(Rmq(L, m, 2 * i, Tl, m), Rmq(m + 1, R, 2 * i + 1, m + 1, Tr));
		}
	}
}

void Add1(int i, int D, int L, int R, int node) {
	if (L == R) {
		A[i] += D;
		T[node] += D;
	}
	else {
		int mid = (L + R) / 2;
		if (i <= mid) {
			Add1(i, D, L, mid, 2 * node);
		}
		else {
			Add1(i, D, mid + 1, R, 2 * node + 1);
		}
		T[node] = max(T[2 * node], T[2 * node + 1]);
	}
}

void Add2(int i, int j, int D, int L, int R, int node) {
	if (L == R) {
		T[node] += D;
		A[L] += D;
	}
	else {
		int mid = (L + R) / 2;
		if (i <= mid) {
			Add2(i, min(j, mid), D, L, mid, 2 * node);
		}
		if (j > mid) {
			Add2(max(i, mid + 1), j, D, mid + 1, R, 2 * node + 1);
		}
		T[node] = max(T[2 * node], T[2 * node + 1]);
	}
}
int main() {
	ifstream inputFile("input.txt");
	
	int n;
	inputFile >> n;

	A.resize(n + 1);
	T.resize(4 * n);
	Add.resize(4 * n);

	for (int i = 1; i <= n; i++) {
		inputFile >> A[i];
	}

	Build(1, 1, n);

	string operation;
	while (cin >> operation) {
		if (operation == "Rmq") {
			int L, R;
			cin >> L >> R;
			int result = Rmq(L, R, 1, 1, n);
			cout << result << endl;
		}
		else if (operation == "Add1") {
			int index, D;
			cin >> index >> D;
			Add1(index, D, 1, n, 1);
			for (int i = 1; i <= n; i++) {
				cout << A[i] << " ";
			}
			cout << endl;
		}
		else if (operation == "Add2") {
			int L, R, D;
			cin >> L >> R >> D;
			Add2(L, R, D, 1, n, 1);
			for (int i = 1; i <= n; i++) {
				cout << A[i] << " ";
			}
			cout << endl;
		}
	}

	inputFile.close();

	return 0;
}
