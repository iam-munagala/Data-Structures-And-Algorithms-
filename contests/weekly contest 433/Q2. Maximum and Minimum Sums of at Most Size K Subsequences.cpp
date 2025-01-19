#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_K = 100;

class Solution {
public:
    int subsequenceSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute factorials and inverse factorials modulo MOD
        vector<long long> fact(n + 1, 1), inv_fact(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }

        // Function to compute binomial coefficient C(n, r) % MOD
        auto binom = [&](int n, int r) -> long long {
            if (r > n || r < 0) return 0;
            return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
        };

        long long total_sum = 0;

        // Consider nums[i] as the minimum element in a subsequence
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                total_sum = (total_sum + nums[i] * binom(n - i - 1, j - 1)) % MOD;
            }
        }

        // Consider nums[i] as the maximum element in a subsequence
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                total_sum = (total_sum + nums[i] * binom(i, j - 1)) % MOD;
            }
        }

        return total_sum;
    }

private:
    // Function to compute modular inverse using Fermat's Little Theorem
    long long modInverse(long long x) {
        return power(x, MOD - 2);
    }

    // Function to compute x^y % MOD
    long long power(long long x, long long y) {
        long long res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            y /= 2;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution sol;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << sol.subsequenceSum(arr, k) << endl;
    }
    return 0;
}
