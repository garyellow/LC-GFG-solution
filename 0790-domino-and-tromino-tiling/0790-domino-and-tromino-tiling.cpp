class Solution {
public:
    static vector<int> dp;
    
    int numTilings(int n) {
        dp[1] = 1, dp[2] = 2, dp[3] = 5;
        return recursive(n);
    }
    
    long recursive(int n) {
        return dp[n] ? dp[n] : dp[n] = (recursive(n - 1) * 2 + recursive(n - 3)) % int(1e9 + 7);
    }
};

vector<int> Solution::dp = vector<int>(1001,0);