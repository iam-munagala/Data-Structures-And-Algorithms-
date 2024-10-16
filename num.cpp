#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int minOperations(vector<int>& change, vector<int>& arr) {
    int n = arr.size();
    vector<bool> isNull(n, false);
    int steps = 0;
    
    while (true) {
        bool allNull = true;
        bool progressMade = false;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                allNull = false;
                break;
            }
        }
        
        if (allNull) return steps;
        
        for (int i = 0; i < n; i++) {
            int index = change[i] - 1;
            
            if (arr[index] == 0 && !isNull[index]) {
                arr[index] = -1;
                isNull[index] = true;
                progressMade = true;
            } else if (arr[index] > 0) {
                arr[index]--;
                progressMade = true;
            }
        }
        
        steps++;
        
        if (!progressMade) return -1;
    }
    
    return steps;
}

int main() {
    int n = 10;

    vector<int> change = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr = {3, 2, 1, 0, 2, 0, 3, 2, 1, 0};

    int result = minOperations(change, arr);

    if (result == -1) {
        cout << "It's not possible to set all elements to NULL" << endl;
    } else {
        cout << "Minimum number of operations: " << result << endl;
    }

    return 0;
}
