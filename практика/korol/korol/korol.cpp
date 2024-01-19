#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int m, n, x, y;

	input >> m;

	for (int i = 0; i < m; i++) {
		input >> x >> y;

		n = max(x, y) + abs(x - y); 
		if (n % 2 == 1) { 
			output << "2\n"; 
		}
		else { 
			output << "1\n"; 
		}
	}


	return 0;
}
