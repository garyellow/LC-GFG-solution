class Solution {
public:
    double soupServings(int n) {
        if(n >= 5000) return 1;
        
        n = ceil(n / 25.0);
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        
        return helper(n, n, dp);
    }
    
    double helper(int a, int b, vector<vector<double>> &dp) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;
        
        if(dp[a][b] == -1) {
            dp[a][b] = 0;
            
            dp[a][b] += helper(a - 4, b, dp);
            dp[a][b] += helper(a - 3, b - 1, dp);
            dp[a][b] += helper(a - 2, b - 2, dp);
            dp[a][b] += helper(a - 1, b - 3, dp);
            
            dp[a][b] /= 4;
        }
        
        return dp[a][b];
    }
};