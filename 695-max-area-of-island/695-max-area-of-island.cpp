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
        
        try
        {
            if(grid.at(i).at(j))
            {
                grid[i][j] = 0;
                
                sum += 1;
                sum += DFS(grid, i - 1, j);
                sum += DFS(grid, i + 1, j);
                sum += DFS(grid, i, j - 1);
                sum += DFS(grid, i, j + 1);
            }
        }
        catch(exception) {}
            
        return sum;
    }
};