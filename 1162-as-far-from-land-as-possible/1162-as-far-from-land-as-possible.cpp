class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> arr;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.front().size(); j++) {
                if(grid[i][j]) {
                    arr.push({i, j});
                }
            }
        }
        
        if(arr.size() == 0 || arr.size() == grid.size() * grid.front().size()) return -1;
        
        int step;
        for(step = -1; arr.size(); step++) {
            for(int n = arr.size(); n--;) {
                auto [x, y] = arr.front();
                arr.pop();
                
                if(x + 1 < grid.size() && grid[x + 1][y] == 0) {
                    grid[x + 1][y] = 1;
                    arr.push({x + 1, y});
                }
                if(x - 1 >= 0 && grid[x - 1][y] == 0) {
                    grid[x - 1][y] = 1;
                    arr.push({x - 1, y});
                }
                if(y + 1 < grid.front().size() && grid[x][y + 1] == 0) {
                    grid[x][y + 1] = 1;
                    arr.push({x, y + 1});
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 0) {
                    grid[x][y - 1] = 1;
                    arr.push({x, y - 1});
                }
            }
        }
        
        return step;
    }
};