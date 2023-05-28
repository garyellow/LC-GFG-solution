class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp = vector<vector<int>>(cuts.size(), vector<int>(cuts.size(), INT_MAX));
        
        return helper(1, cuts.size() - 2, cuts, dp);
    }
    
    int helper(int l, int r, vector<int>& cuts, vector<vector<int>> &dp) {
        if(l > r) return 0;
        else if(dp[l][r] == INT_MAX) {
            for(auto cur = l; cur <= r; cur++) {
                dp[l][r] = min(dp[l][r], helper(l, cur - 1, cuts, dp) + helper(cur + 1, r, cuts, dp) + cuts[r + 1] - cuts[l - 1]);
            }
        }
        
        return dp[l][r];
    }
};