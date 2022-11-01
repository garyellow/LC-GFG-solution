class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        
        for(int i = 0; i < grid.front().size(); i++) {
            int x = i, y = 0;
            
            while(y < grid.size()) {
                if(grid[y][x] == 1) {
                    if(x + 1 < grid.front().size() && grid[y][x + 1] == 1) {
                        x++;
                        y++;
                    }
                    else break;
                }
                else {
                    if(x - 1 >= 0 && grid[y][x - 1] == -1) {
                        x--;
                        y++;
                    }
                    else break;
                }
            }
            
            ans.push_back(y == grid.size() ? x : -1);
        }
        
        return ans;
    }
};