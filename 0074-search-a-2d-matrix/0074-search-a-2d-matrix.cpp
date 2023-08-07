class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto first = lower_bound(matrix.begin(), matrix.end(), vector<int>({target}), [&](vector<int> i, vector<int> j) { return i.back() < j.back(); });
        
        if(first == matrix.end()) return false;
        
        auto second = lower_bound(first->begin(), first->end(), target);
        return second == first->end() ? false : target == *second;
    }
};