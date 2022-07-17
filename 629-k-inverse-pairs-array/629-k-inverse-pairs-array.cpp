class Solution {
public:
    array<array<int, 1001>, 1001> dp;
    
    Solution() {
        if(!dp[0][0])
        {
            dp[0][0] = 1;
            for (int i = 1; i < dp.size(); i++)
            {
                long temp = 0;
                for (int j = 0; j < dp.front().size(); j++)
                {
                    temp += dp[i - 1][j];
                    if (j >= i) temp -= dp[i - 1][j - i];
                    dp[i][j] = temp % int(1e9 + 7); 
                }
            }
        }
    }
    
    int kInversePairs(int n, int k) {
        return dp[n][k];
    }
};