class Solution {
public:
    static vector<vector<double>> dp;
    Solution() {
        if(dp.empty()) {
            dp = vector<vector<double>>(201, vector<double>(201, -1));
        }
    }
    
    double soupServings(int n) {
        if(n >= 5000) return 1;
        
        n = ceil(n / 25.0);
        
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

vector<vector<double>> Solution::dp;