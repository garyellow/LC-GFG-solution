class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return maxMove;
        vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(maxMove + 1)));
        
        for(int i = 0; i < m; i++)
        {
            dp[i][0][1] += 1;
            dp[i][n - 1][1] += 1;
        }
        
        for(int j = 0; j < n; j++)
        {
            dp[0][j][1] += 1;
            dp[m - 1][j][1] += 1;
        }
        
        for(int step = 2; step <= maxMove; step++)
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dp[i][j][step] += i - 1 >= 0 ? dp[i - 1][j][step - 1] : 0;
                    dp[i][j][step] += j - 1 >= 0 ? dp[i][j - 1][step - 1] : 0;
                    dp[i][j][step] += i + 1 < m ? dp[i + 1][j][step - 1] : 0;
                    dp[i][j][step] += j + 1 < n ? dp[i][j + 1][step - 1] : 0;
                    dp[i][j][step] %= int(1e9 + 7);
                }
            }
        }
        
        return accumulate(dp[startRow][startColumn].begin(), dp[startRow][startColumn].end(), 0, [](long l, long r){return (l + r) % long(1e9 + 7);});
    }
};