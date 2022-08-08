class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(20001);
        
        for(auto &&i : nums)
        {
            dp[10000 + i] = *max_element(dp.begin(), dp.begin() + 10000 + i) + 1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};