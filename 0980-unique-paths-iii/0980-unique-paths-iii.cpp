class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty = 0, x, y;
        for(int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid.front().size(); j++) {
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j] == 1) x = i, y = j;
            }
        
        return bt(x, y, 0, grid, empty + 1);
    }
    
    int bt(int i, int j, int step, vector<vector<int>>& grid, int target) {
        if(grid[i][j] == -1) return 0;
        if(grid[i][j] == 2) return step == target;
        
        int cnt = 0;
        grid[i][j] = -1;
        if(i - 1 >= 0) cnt += bt(i - 1, j, step + 1, grid, target);
        if(j - 1 >= 0) cnt += bt(i, j - 1, step + 1, grid, target);
        if(i + 1 < grid.size()) cnt += bt(i + 1, j, step + 1, grid, target);
        if(j + 1 < grid.front().size()) cnt += bt(i, j + 1, step + 1, grid, target);
        grid[i][j] = 0;
        
        return cnt;
    }
};