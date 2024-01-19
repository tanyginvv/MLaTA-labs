#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("input2.txt");
    ofstream fout("output2.txt");
    int n, k;
    fin >> n >> k;
    vector<vector<char>> forest(n, vector<char>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            fin >> forest[i][j];
        }
    }
    int blocks = 0;
    m:for (int i = 0; i < n; i++) {
        for (int j = 0;j < k; j++) {
            if (forest[i][j] == '0') {
                forest[i][j] = '#';
            }
            else if (forest[i][j] == '1') {
                goto m;
            }
    }
   }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            fout << forest[i][j] << " ";
            cout << forest[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
    
}