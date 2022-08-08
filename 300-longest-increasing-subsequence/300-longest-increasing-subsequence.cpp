class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for(auto &&num : nums)
        {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            
            if(it != dp.end()) *it = num;
            else dp.push_back(num);
        }
        
        return dp.size();
    }
};