class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.front().size(), -1));
        
        return point(grid, grid.size() - 1, grid.front().size() - 1, dp);
    }
    
    int point(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(dp[i][j] == -1) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else if(i == 0) dp[i][j] = point(grid, i, j - 1, dp) + grid[i][j];
            else if(j == 0) dp[i][j] = point(grid, i - 1, j, dp) + grid[i][j];
            else dp[i][j] = min(point(grid, i - 1, j, dp), point(grid, i, j - 1, dp)) + grid[i][j];
        }
        
        return dp[i][j];
    }
};