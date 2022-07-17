class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<short, short> used;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto &&i : nums) used[i]++;
        
        backtrack(nums, vector<int>());
        
        return ans;
    }
    
    void backtrack(vector<int>& nums, vector<int> now)
    {
        if(now.size() == nums.size())
        {
            ans.push_back(now);
            return;
        }
        
        for(auto &&i : used)
        {
            if (i.second)
            {
                i.second--;
                now.push_back(i.first);
                
                backtrack(nums, now);
                
                now.pop_back();
                i.second++;
            }
        }
    }
};