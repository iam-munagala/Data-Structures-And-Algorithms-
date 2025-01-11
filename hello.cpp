#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b) {
    return a.length() > b.length();
}

int main() {
    int n;
    cin >> n;
    vector<string> subs(n);
    for (int i = 0; i < n; i++) {
        cin >> subs[i];
    }
    string mainStr;
    cin >> mainStr;

    sort(subs.begin(), subs.end(), compare);

    int count = 0;
    while (true) {
        bool removed = false;
        for (int i = 0; i < n; i++) {
            size_t found = mainStr.find(subs[i]);
            if (found != string::npos) {
                mainStr.erase(found, subs[i].length());
                removed = true;
                count++;
                break;
            }
        }
        if (!removed) {
            break;
        }
    }

    cout << count << endl;
    return 0;
}
