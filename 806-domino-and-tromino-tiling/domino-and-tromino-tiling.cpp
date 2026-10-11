class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;

        long long a = 1; // dp[i - 3]
        long long b = 1; // dp[i - 2]
        long long c = 2; // dp[i - 1]

        for (int i = 3; i <= n; i++) {
            long long curr = (2 * c % MOD + a) % MOD;

            a = b;
            b = c;
            c = curr;
        }

        return c;
    }
};