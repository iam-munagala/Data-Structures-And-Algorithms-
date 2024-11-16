#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swapNumbers(int &a, int &b) 
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        obj.swapNumbers(a, b); 
        cout << "a = " << a << " b = " << b << endl;
    }
    return 0;
}
