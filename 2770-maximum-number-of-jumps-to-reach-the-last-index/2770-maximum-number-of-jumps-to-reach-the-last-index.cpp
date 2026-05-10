class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), -1);
        dp[0] = 0;

        for (int j = 1; j < nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (dp[i] != -1 && abs(nums[i] - nums[j]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp.back();
    }
};