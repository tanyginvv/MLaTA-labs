#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Person {
	int time;
	int stepsRemaining;
	int finishTime;
};

bool compareTime(const Person& a, const Person& b) {
	return a.time < b.time;
}

bool compareSteps(const Person& a, const Person& b) {
	return a.stepsRemaining < b.stepsRemaining;
}

int main() {
	std::ifstream inputFile("in4.txt");
	std::ofstream outputFile("output.txt");

	int N;
	inputFile >> N;

	std::vector<Person> people(N);

	for (int i = 0; i < N; i++) {
		inputFile >> people[i].time >> people[i].stepsRemaining;
		people[i].finishTime = 0;
	}

	std::sort(people.begin(), people.end(), compareSteps);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (people[i].time < people[j].time && people[i].stepsRemaining >= people[j].stepsRemaining) {
				people[i].finishTime = std::max(people[i].finishTime, people[j].finishTime);
			}
		}
		people[i].finishTime += people[i].time * people[i].stepsRemaining;
	}

	std::sort(people.begin(), people.end(), compareTime);

	for (int i = 0; i < N; i++) {
		outputFile << people[i].finishTime << std::endl;
	}

	return 0;
}
