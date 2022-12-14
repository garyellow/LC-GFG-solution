class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                matrix[i][j] += min({(j - 1 >= 0 ? matrix[i - 1][j - 1] : INT_MAX), matrix[i -1][j], (j + 1 < matrix.size() ? matrix[i - 1][j + 1] : INT_MAX)});
            }
        }
        
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};