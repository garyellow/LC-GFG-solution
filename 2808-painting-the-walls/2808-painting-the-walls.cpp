class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return dfs(0, cost.size(), cost, time, dp);
    }

    int dfs(int cur, int total, vector<int>& cost, vector<int>& time, vector<vector<int>> &dp) {
        if(total <= 0) return 0;
        if(cur == cost.size()) return 1e9;
        if(dp[cur][total] != -1) return dp[cur][total];

        int free = dfs(cur + 1, total, cost, time, dp);
        int paid = cost[cur] + dfs(cur + 1, total - time[cur] - 1, cost, time, dp);
        return dp[cur][total] = min(free, paid);
    }
};