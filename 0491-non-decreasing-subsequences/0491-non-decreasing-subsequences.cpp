class Solution {
public:
    set<vector<int>> ans;
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        backtracking(-1, temp, nums);
        
        return {ans.begin(), ans.end()};
    }
    
    void backtracking(int index, vector<int>& cur, vector<int>& nums) {
        if(cur.size() >= 2) ans.insert(cur);
        
        for(int i = index + 1; i < nums.size(); i++) {
            if(index == -1 || nums[i] >= nums[index]) {
                cur.push_back(nums[i]);
                backtracking(i, cur, nums);
                cur.pop_back();
            }
        }
    }
};