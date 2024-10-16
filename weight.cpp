#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> positions(n);
    
    // Input the current book positions
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    // Calculate the minimum number of moves
    // The number of moves is the difference between consecutive books
    int moves = 0;
    for (int i = 1; i < n; ++i) {
        moves += positions[i] - positions[i - 1] - 1; // Count the gaps between consecutive books
    }

    // Output the result
    cout << moves << endl;

    return 0;
}
