class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int cnt = 0;
        
        for(int i = 0; i < mat.size(); i++) {
            cnt += mat[i][i];
            
            if(i != mat.size() - i - 1) {
                cnt += mat[mat.size() - i - 1][i];
            }
        }
        
        return cnt;
    }
};