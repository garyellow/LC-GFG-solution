class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> qu;

        for(int i = 0; i< mat.size(); i++) {
            for(int j = 0; j < mat.front().size(); j++) {
                if(mat[i][j] == 0) {
                    qu.push({i, j});
                }
                mat[i][j] = -1;
            }
        }

        for(int step = 0; qu.size(); step++) {
            for(int n = qu.size(); n--;) {
                auto [x, y] = qu.front();
                qu.pop();

                if(mat[x][y] == -1) mat[x][y] = step;
                if(x - 1 >= 0 && mat[x - 1][y] == -1) qu.push({x - 1, y}); 
                if(y - 1 >= 0 && mat[x][y - 1] == -1) qu.push({x, y - 1}); 
                if(x + 1 < mat.size() && mat[x + 1][y] == -1) qu.push({x + 1, y}); 
                if(y + 1 < mat.front().size() && mat[x][y + 1] == -1) qu.push({x, y + 1}); 
            }
        }

        return mat;
    }
};