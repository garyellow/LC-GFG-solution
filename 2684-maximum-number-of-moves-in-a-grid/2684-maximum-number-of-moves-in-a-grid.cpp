class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.front().size()));

        int ans = 0;
        for (int j = 1; j < grid.front().size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                for (int cur = max(0, i - 1); cur <= min(int(grid.size()) - 1, i + 1); cur++) {
                    if (grid[i][j] > grid[cur][j - 1]) {
                        dp[i][j] = max(dp[i][j], dp[cur][j - 1] + 1);
                    }
                }
                if (dp[i][j] == 0) dp[i][j] = -1;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};