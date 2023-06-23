class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int, int>> dp(nums.size());
        
        int ans = 0;
        for(int cur = 0; cur < nums.size(); cur++) {
            for(int last = 0; last < cur; last++) {
                int d = nums[cur] - nums[last];
                
                ans = max(ans, dp[cur][d] = dp[last].count(d) ? dp[last][d] + 1 : 2);
            }
        }
        
        return ans;
    }
};