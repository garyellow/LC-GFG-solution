class Solution {
    int helper(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (l == r)
            return nums[l];

        if (dp[l][r] != -1)
            return dp[l][r];

        return dp[l][r] = max(nums[l] - helper(nums, l + 1, r, dp),
                              nums[r] - helper(nums, l, r - 1, dp));
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        vector dp(nums.size(), vector(nums.size(), -1));
        return helper(nums, 0, nums.size() - 1, dp) >= 0;
    }
};