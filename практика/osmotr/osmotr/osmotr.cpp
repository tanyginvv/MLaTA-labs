#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> in_degree(n, 0);
	vector < vector < int>> adj_list(n, vector<int>());

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;

		for (int j = 0; j < m; j++) {
			int v;
			cin >> v;
			v--;
			adj_list[v].push_back(i);
			in_degree[i]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> order;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		order.push_back(v);
		for (int u : adj_list[v]) {
			if (--in_degree[u] == 0) {
				q.push(u);
			}
		}
	}

	if (order.size() != n) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int v : order) {
			cout << v + 1 << endl;
		}
	}

	return 0;
}
