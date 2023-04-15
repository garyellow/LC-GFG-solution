class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1));
        return cal(0, k, piles, dp);
    }
    
    int cal(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (dp[i][k]) return dp[i][k];
        if (i == piles.size() || k == 0) return 0;
        
        int res = cal(i + 1, k, piles, dp), cur = 0;
        for (int j = 0; j < piles[i].size() && j < k; j++) {
            cur += piles[i][j];
            res = max(res, cal(i + 1, k - j - 1, piles, dp) + cur);
        }
        
        return dp[i][k] = res;
    }
};