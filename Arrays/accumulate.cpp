#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> ar = {1, 2, 3, 8, 9};

    auto front = ar.begin();
    auto back = ar.end();

    cout << accumulate(front, back, 0) << endl;
    return 0;
}