#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i];
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int j = i - 1;
        while (D[i] > 0 && j >= 0) {  // изменение условия
            if (ans[j] == 0 && D[i] + j >= i) {
                D[i]--;
            }
            j--;
        }
        ans[i] = j + 1;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}