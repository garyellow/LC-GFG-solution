class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][0] == 1) dig(i, 0, grid);
            if(grid[i][grid.front().size() - 1] == 1) dig(i, grid.front().size() - 1, grid);
        }
        
        for(int j = 0; j < grid.front().size(); j++) {
            if(grid[0][j] == 1) dig(0, j, grid);
            if(grid[grid.size() - 1][j] == 1) dig(grid.size() - 1, j, grid);
        }
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.front().size(); j++) {
                if(grid[i][j] == 1) {
                    ans += dig(i, j, grid);
                }
            }
        }
        
        return ans;
    }
    
    int dig(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0; 
        
        int cnt = 1;
        if(i - 1 >= 0 && grid[i - 1][j] == 1) 
            cnt += dig(i - 1, j, grid);
        
        if(j - 1 >= 0 && grid[i][j - 1] == 1) 
            cnt += dig(i, j - 1, grid);
        
        if(i + 1 < grid.size() && grid[i + 1][j] == 1) 
            cnt += dig(i + 1, j, grid);
        
        if(j + 1 < grid.front().size() && grid[i][j + 1] == 1) 
            cnt += dig(i, j + 1, grid);
        
        return cnt;
    }
};