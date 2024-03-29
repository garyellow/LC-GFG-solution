class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        dp.front() = 1;
        
        int cnt = 0;
        for(int i = low; i <= high; i++) 
            cnt = (cnt + check(i, dp, zero, one)) % int(1e9 + 7);
        
        return cnt;
    }
    
    long check(int cur, vector<int> &dp, int zero, int one) {
        if(cur < 0) return 0;
        else if(dp[cur] == -1) dp[cur] = (check(cur - zero, dp, zero, one) + check(cur - one, dp, zero, one)) % int(1e9 + 7);
        
        return dp[cur];
    }
};