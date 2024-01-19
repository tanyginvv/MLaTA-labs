#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 1) {
        cout << "1" << endl;
        cout << "1" << endl;
        return 0;
    }

    if (N % 2 == 0) {
        cout << "No";
        return 0;
    }
    vector<int> amplifiers; 

    while (N > 0) {
        if (N % 2 == 0) {
            
            amplifiers.push_back(1);
            N = N / 2 ;
        }
        else {
           
            amplifiers.push_back(2);
            N = N/ 2 ;
        }
    }

    int numAmplifiers = amplifiers.size(); 

    cout << numAmplifiers - 1  << endl;
    for (int i = numAmplifiers -1; i >= 1   ; i--) {
        cout << amplifiers[i] << " ";
    }

    return 0;
}