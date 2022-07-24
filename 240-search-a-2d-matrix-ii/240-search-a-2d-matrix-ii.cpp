class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0, j = matrix.front().size() - 1; i < matrix.size() && j >= 0; matrix[i][j] > target ? j-- : i++)
            if(matrix[i][j] == target) return true;
        
        return false;
    }
};