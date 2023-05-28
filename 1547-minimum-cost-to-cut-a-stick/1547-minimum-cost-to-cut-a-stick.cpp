class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        unordered_map<int, unordered_map<int, int>> dp;
        
        sort(cuts.begin(), cuts.end());
        
        return helper(0, n, cuts, dp);
    }
    
    int helper(int l, int r, vector<int>& cuts, unordered_map<int, unordered_map<int, int>> &dp) {
        auto s = upper_bound(cuts.begin(), cuts.end(), l), e = lower_bound(cuts.begin(), cuts.end(), r);
        
        if(s == e) return 0;
        else if(!dp[l][r]) {
            dp[l][r] = INT_MAX;
            for(auto it = s; it != e; it++) {
                dp[l][r] = min(dp[l][r], helper(l, *it, cuts, dp) + helper(*it, r, cuts, dp) + r - l);
            }
        }
        
        return dp[l][r];
    }
};