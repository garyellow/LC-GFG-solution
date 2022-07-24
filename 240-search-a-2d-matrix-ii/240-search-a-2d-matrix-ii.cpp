class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &&line : matrix)
            if(line.front() <= target && line.back() >= target)
                if(*lower_bound(line.begin(), line.end(), target) == target)
                    return true;
        
        return false;
    }
};