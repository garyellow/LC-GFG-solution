class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        if(dp[n] == 0) dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        
        return dp[n];
    }
    
    static vector<int> dp;
};

vector<int> Solution::dp = vector<int>(46);