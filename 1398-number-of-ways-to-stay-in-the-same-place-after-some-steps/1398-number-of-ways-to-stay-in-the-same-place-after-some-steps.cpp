class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        return dfs(0, steps, arrLen, dp);
    }

    long dfs(int cur, int remain, int arrLen, vector<vector<int>> &dp) {
        if(cur < 0 || cur >= arrLen) return 0;
        if(remain == 0) return cur == 0;
        if(dp[cur][remain] != -1) return dp[cur][remain];

        dp[cur][remain] = 0;
        dp[cur][remain] = (dp[cur][remain] + dfs(cur - 1, remain - 1, arrLen, dp)) % int(1e9 + 7);
        dp[cur][remain] = (dp[cur][remain] + dfs(cur, remain - 1, arrLen, dp)) % int(1e9 + 7);
        dp[cur][remain] = (dp[cur][remain] + dfs(cur + 1, remain - 1, arrLen, dp)) % int(1e9 + 7);

        return dp[cur][remain];
    }
};