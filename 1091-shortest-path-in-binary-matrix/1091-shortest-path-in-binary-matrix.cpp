class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.front().front()) return -1;
        
        vector<vector<bool>> isGone = vector<vector<bool>>(grid.size(), vector<bool>(grid.size()));
        
        isGone.front().front() = true;
        queue<pair<int, int>> bfs({{0, 0}});
        
        for(int step = 2; bfs.size(); step++) {
            for(int n = bfs.size(); n--;) {
                auto [x, y] = bfs.front();
                bfs.pop();
                
                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        if(x + dx >= 0 && x + dx < grid.size() && y + dy >= 0 && y + dy < grid.size() && !grid[x + dx][y + dy] && !isGone[x + dx][y + dy]) {
                            isGone[x + dx][y + dy] = true;
                            if(x + dx == grid.size() - 1 && y + dy == grid.size() - 1) return step;
                            else bfs.push({x + dx, y + dy});
                        }
                    }
                }
            }
        }
        
        return grid.size() == 1 ? 1 : -1;
    }
};