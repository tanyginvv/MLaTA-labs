#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Point {
	int x, y;

	Point(int x_, int y_) : x(x_), y(y_) {}
};

int main() {
	ifstream fin("in4.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;

	vector<Point> points;
	for (int i = 0; i < n; i++) {
		int x, y;
		fin >> x >> y;
		points.emplace_back(x, y);
	}

	int left_turns = 0, right_turns = 0, straight_turns = 0;
	for (int i = 1; i < n - 1; i++) {
		int dx1 = points[i].x - points[i - 1].x;
		int dy1 = points[i].y - points[i - 1].y;
		int dx2 = points[i + 1].x - points[i].x;
		int dy2 = points[i + 1].y - points[i].y;

		int cross_product = dx1 * dy2 - dx2 * dy1;
		int cross2 = dx1 * dx2 + dy1 * dy2;
		if (cross_product > 0) {
			left_turns++;
		}
		if (cross_product < 0) {
			right_turns++;
		}
		if(cross2 == 0) {
			straight_turns++;
		}
	}

	fout  << left_turns << " " << straight_turns  << endl;

	return 0;
}
