class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j = grid.front().size() - 1, cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            while(j >= 0 && grid[i][j] < 0) j--;
            
            cnt += grid.front().size() - j - 1;
        }
        
        return cnt;
    }
};