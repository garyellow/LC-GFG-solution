class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<bool>> isGone(grid.size(), vector<bool>(grid.front().size()));
        
        queue<pair<int, int>> island1;
        for(int i = 0; island1.empty() && i < grid.size(); i++) {
            for(int j = 0; island1.empty() && j < grid.front().size(); j++) {
                if(grid[i][j]) {
                    island1.push({i, j});
                    isGone[i][j] = true;
                }
            }
        }
        
        queue<pair<int, int>> newLand;
        
        while(island1.size()) {
            auto [x, y] = island1.front();
            island1.pop();
            
            if(x - 1 >= 0 && !isGone[x - 1][y]) {
                isGone[x - 1][y] = true;
                
                if(grid[x - 1][y]) island1.push({x - 1, y});
                else newLand.push({x - 1, y});
            }
            
            if(y - 1 >= 0 && !isGone[x][y - 1]) {
                isGone[x][y - 1] = true;
                
                if(grid[x][y - 1]) island1.push({x, y - 1});
                else newLand.push({x, y - 1});
            }
            
            if(x + 1 < grid.size() && !isGone[x + 1][y]) {
                isGone[x + 1][y] = true;
                
                if(grid[x + 1][y]) island1.push({x + 1, y});
                else newLand.push({x + 1, y});
            }
            
            if(y + 1 < grid.front().size() && !isGone[x][y + 1]) {
                isGone[x][y + 1] = true;
                
                if(grid[x][y + 1]) island1.push({x, y + 1});
                else newLand.push({x, y + 1});
            }
        }
        
        for(int time = 1; newLand.size(); time++) {
            for(int n = newLand.size(); n--;) {
                auto [x, y] = newLand.front();
                newLand.pop();

                if(x - 1 >= 0 && !isGone[x - 1][y]) {
                    isGone[x - 1][y] = true;

                    if(grid[x - 1][y]) return time;
                    else newLand.push({x - 1, y});
                }

                if(y - 1 >= 0 && !isGone[x][y - 1]) {
                    isGone[x][y - 1] = true;

                    if(grid[x][y - 1]) return time;
                    else newLand.push({x, y - 1});
                }

                if(x + 1 < grid.size() && !isGone[x + 1][y]) {
                    isGone[x + 1][y] = true;

                    if(grid[x + 1][y]) return time;
                    else newLand.push({x + 1, y});
                }

                if(y + 1 < grid.front().size() && !isGone[x][y + 1]) {
                    isGone[x][y + 1] = true;

                    if(grid[x][y + 1]) return time;
                    else newLand.push({x, y + 1});
                }
            }
        }
        
        return 0;
    }
};