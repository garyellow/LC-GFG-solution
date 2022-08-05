class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        
        for(auto &&num : nums)
            if(num <= target) dp[num] = 1;
        
        for(int i = 1; i <= target; i++)
            for(auto &&num : nums)
                if(i - num > 0)
                    dp[i] = min(0L + dp[i] + dp[i - num], 0L + INT_MAX);
        
        return dp.back();
    }
};