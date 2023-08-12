class Solution {
public:
    vector<vector<int>> dp;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int i = 0, int j = 0) {
        if(!dp.capacity()) {
            dp = vector<vector<int>>(obstacleGrid.size(), vector<int>(obstacleGrid.front().size()));
            dp[obstacleGrid.size() - 1][obstacleGrid.front().size() - 1] = 1;
        }
        
        if(i == obstacleGrid.size() || j == obstacleGrid.front().size() || obstacleGrid[i][j] == 1) return 0;
        return dp[i][j] ? dp[i][j] : dp[i][j] = uniquePathsWithObstacles(obstacleGrid, i + 1, j) + uniquePathsWithObstacles(obstacleGrid, i, j + 1);
    }
};