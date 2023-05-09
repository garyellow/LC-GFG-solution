class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir = 0, x = 0, y = 0;
        vector<pair<int,int>> d({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
        vector<int> ans;
        
        do {
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -101;
            
            while(ans.size() < matrix.size() * matrix.front().size() && (x + d[dir].first < 0 || x + d[dir].first >= matrix.size() || y + d[dir].second < 0 || y + d[dir].second >= matrix.front().size() || matrix[x + d[dir].first][y + d[dir].second] < -100)) 
                dir = (dir + 1) % 4;
            
            x += d[dir].first;
            y += d[dir].second;
        } while(ans.size() < matrix.size() * matrix.front().size());
        
        return ans;
    }
};