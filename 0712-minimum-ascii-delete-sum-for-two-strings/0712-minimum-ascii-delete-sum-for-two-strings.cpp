class Solution {
public:
    int minimumDeleteSum(string &s1, string &s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), INT_MAX));
        
        return helper(0, 0, s1, s2, dp);
    }
    
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == s1.size()) {
            return accumulate(s2.begin() + j, s2.end(), 0);
        }
        if(j == s2.size()) {
            return accumulate(s1.begin() + i, s1.end(), 0);
        }
        
        if(dp[i][j] == INT_MAX) {
            dp[i][j] = min(s1[i] + helper(i + 1, j, s1, s2, dp), s2[j] + helper(i, j + 1, s1, s2, dp));
            if(s1[i] == s2[j]) dp[i][j] = min(dp[i][j], helper(i + 1, j + 1, s1, s2, dp));
        }
        
        return dp[i][j];
    }
};