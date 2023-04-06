class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][0] == 0) fill(i, 0, grid);
            if(grid[i][grid.front().size() - 1] == 0) fill(i, grid.front().size() - 1, grid);
        }
        
        for(int j = 0; j < grid.front().size(); j++) {
            if(grid[0][j] == 0) fill(0, j, grid);
            if(grid[grid.size() - 1][j] == 0) fill(grid.size() - 1, j, grid);
        }
        
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.front().size(); j++) {
                if(grid[i][j] == 0) {
                    cnt++;
                    fill(i, j, grid);
                }
            }
        }
        
        return cnt;
    }
    
    void fill(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 1; 
        
        if(i - 1 >= 0 && grid[i - 1][j] == 0) 
            fill(i - 1, j, grid);
        
        if(j - 1 >= 0 && grid[i][j - 1] == 0) 
            fill(i, j - 1, grid);
        
        if(i + 1 < grid.size() && grid[i + 1][j] == 0) 
            fill(i + 1, j, grid);
        
        if(j + 1 < grid.front().size() && grid[i][j + 1] == 0) 
            fill(i, j + 1, grid);
    }
};