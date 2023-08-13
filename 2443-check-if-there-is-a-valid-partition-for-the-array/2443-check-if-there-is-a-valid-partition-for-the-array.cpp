class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> isGone(nums.size());
        vector<bool> dp(nums.size());

        return helper(0, nums, isGone, dp);
    }
    
    bool helper(int cur, vector<int>& nums, vector<bool> &isGone, vector<bool> &dp) {
        if(cur == nums.size()) return true;

        if(!isGone[cur]) {
            isGone[cur] = true;

            if(cur + 1 < nums.size() && nums[cur] == nums[cur + 1]) {
                if(helper(cur + 2, nums, isGone, dp)) {
                    return dp[cur] = true; 
                }
            }

            if(cur + 2 < nums.size() && ((nums[cur] == nums[cur + 1] && nums[cur + 1] == nums[cur + 2]) || (nums[cur] + 1 == nums[cur + 1] && nums[cur + 1] + 1 == nums[cur + 2]))) {
                if(helper(cur + 3, nums, isGone, dp)) {
                    return dp[cur] = true; 
                }
            }
        }

        return dp[cur] = false;
    }
};