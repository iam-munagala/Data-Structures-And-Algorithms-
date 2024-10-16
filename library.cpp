#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int min_moves = positions[n-1] - positions[0] - (n - 1);

    cout << min_moves << endl;

    return 0;
}