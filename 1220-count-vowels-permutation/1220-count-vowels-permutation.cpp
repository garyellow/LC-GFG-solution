class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> dp(5, 1);
        
        while(--n)
        {
            long a = (dp[1] + dp[2] + dp[4]) % (long)(1e9 + 7);
            long e = (dp[0] + dp[2]) % (long)(1e9 + 7);
            long i = (dp[1] + dp[3]) % (long)(1e9 + 7);
            long o = (dp[2]) % (long)(1e9 + 7);
            long u = (dp[2] + dp[3]) % (long)(1e9 + 7);
            
            dp[0] = a, dp[1] = e, dp[2] = i, dp[3] = o, dp[4] = u;
        }
        
        
        return accumulate(dp.begin(), dp.end(), 0, [](auto &x, auto &y) { return (x + y) % int(1e9 + 7); });
    }
};