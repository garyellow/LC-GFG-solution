class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp = vector<vector<int>>(grid.size(), vector<int>(grid.front().size()));
        
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.front().size(); j++) {
                cnt = (cnt + solve(i, j, 0, grid, dp)) % int(1e9 + 7);
            }
        }
        
        return cnt;
    }
    
    long solve(int x, int y, int last, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid.front().size() || grid[x][y] <= last) return 0;
        else if(!dp[x][y]) {
            long temp = 1;
            temp += solve(x + 1, y, grid[x][y], grid, dp);
            temp += solve(x - 1, y, grid[x][y], grid, dp);
            temp += solve(x, y + 1, grid[x][y], grid, dp);
            temp += solve(x, y - 1, grid[x][y], grid, dp);
            
            dp[x][y] = temp % int(1e9 + 7);
        }
        
        return dp[x][y];
    }
};