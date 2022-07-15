class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.front().size(); j++)
                ans = max(ans, DFS(grid, i, j));
        
        return ans;
    }
    
    int DFS(vector<vector<int>>& grid, const int i, const int j)
    {
        int sum = 0;
        
        if(grid[i][j])
        {
            grid[i][j] = 0;
            
            sum += 1;
            sum += i - 1 >= 0 ? DFS(grid, i - 1, j) : 0;
            sum += i + 1 < grid.size() ? DFS(grid, i + 1, j) : 0;
            sum += j - 1 >= 0 ? DFS(grid, i, j - 1) : 0;
            sum += j + 1 < grid.front().size() ? DFS(grid, i, j + 1) : 0;
        }
        
        return sum;
    }
};