class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);
        
        if(check(0, stoneValue, dp))
            return check(0, stoneValue, dp) > 0 ? "Alice" : "Bob";
        
        return "Tie";
    }
    
    int check(int cur, vector<int>& stoneValue, vector<int> &dp) {
        if(cur == stoneValue.size()) return 0;
        else if(dp[cur] == INT_MIN) {
            int cnt = 0;
            for(int tack = 0; cur + tack < stoneValue.size() && tack <= 2; tack++) {
                cnt += stoneValue[cur + tack];
                dp[cur] = max(dp[cur], cnt - check(cur + tack + 1, stoneValue, dp));
            }
        }
        
        return dp[cur];
    }
};