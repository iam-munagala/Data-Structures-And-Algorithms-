#include <iostream>
using namespace std;

char findKthCharacter(int k) {
    string word = "a";
    while (word.size() < k) {
        string nextWord = "";
        for (char c : word) {
            nextWord += (c == 'z') ? 'a' : char(c + 1);
        }
        word += nextWord;
    }
    return word[k - 1];
}

int main() {
    int k;
    cin >> k;
    cout << findKthCharacter(k) << endl;
    return 0;
}
