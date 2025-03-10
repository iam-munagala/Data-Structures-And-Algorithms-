/* 

Reverse the given number 

input - N (12345)

output - N (54321)

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, reversedNum = 0;
    cin >> num;

    while (num > 0) {
        int lastDigit = num % 10;  
        reversedNum = reversedNum * 10 + lastDigit;  
        num /= 10;  
    }

    cout << reversedNum << endl;
    return 0;
}
