class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> dp(1 << 14, -1);

        vector<vector<int>> g(nums.size(), vector<int>(nums.size()));
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                g[i][j] = gcd(nums[i], nums[j]);

        return func(nums, 1, 0, dp, g);
    }
    
    int func(vector<int>& nums, int op, int mask, vector<int>& dp, vector<vector<int>>& g){
        if(op > nums.size() / 2) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i = 0; i < nums.size(); i++){
            if(mask & (1<<i)) continue;
            for(int j = i + 1; j < nums.size(); j++){
                if(mask & (1<<j)) continue;
                
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * g[i][j] + func(nums, op + 1, newMask, dp, g);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }
};