class Solution {
public:
    vector<vector<int>> dp;
    long mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        dp[0][0] = 1;
        
        return check(n, k, target);
    }
    
    int check(int n, int k, int target) {
        if(bool(n) ^ bool(target))
            return 0;
        
        if(dp[n][target] == -1) {
            long sum = 0;
            for(int i = 1; i <= k; i++) {
                if(target - i >= 0) sum = (sum + check(n - 1, k, target - i)) % mod;
                else break;
            }
            
            dp[n][target] = sum;
        }
        
        return dp[n][target];
    }
};