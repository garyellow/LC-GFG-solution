class Solution {
public:
    int countVowelPermutation(int n) {
        array<long, 5> dp({1,1,1,1,1});
        int temp[5];
        
        while(--n)
        {
            temp[0] = (dp[1] + dp[2] + dp[4]) % (long)(1e9 + 7);
            temp[1] = (dp[0] + dp[2]) % (long)(1e9 + 7);
            temp[2] = (dp[1] + dp[3]) % (long)(1e9 + 7);
            temp[3] = (dp[2]) % (long)(1e9 + 7);
            temp[4] = (dp[2] + dp[3]) % (long)(1e9 + 7);
            
            dp[0] = temp[0], dp[1] = temp[1], dp[2] = temp[2], dp[3] = temp[3], dp[4] = temp[4];
        }
        
        
        return accumulate(dp.begin(), dp.end(), 0, [](auto &x, auto &y) { return (x + y) % int(1e9 + 7); });
    }
};