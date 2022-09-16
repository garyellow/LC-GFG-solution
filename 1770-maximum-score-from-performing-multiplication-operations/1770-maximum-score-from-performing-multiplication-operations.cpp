class Solution {
public:
    vector<vector<int>> dp;
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp = vector<vector<int>>(multipliers.size(), vector<int>(multipliers.size(), INT_MIN));
        return check(0, 0, nums, multipliers);
    }
    
    int check(int i, int j, vector<int> &nums, vector<int> &multipliers)
    {
        
        if (j == multipliers.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        int left = check(i + 1, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        int right = check(i, j + 1, nums, multipliers) + (nums[(nums.size() - 1) - (j - i)] * multipliers[j]);
        
        return dp[i][j] = max(left, right);
    }
};