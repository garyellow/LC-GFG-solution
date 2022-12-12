class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        return dp[n] ? dp[n] : dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
    
    static vector<int> dp;
};

vector<int> Solution::dp = vector<int>(46);