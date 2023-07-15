class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        
        vector<vector<int>> dp(events.size() + 5, vector<int>(k + 1, -1));
        
        return helper(0, dp, events, k);
    }
    
    int helper(int cur, vector<vector<int>>& dp, vector<vector<int>>& events, int k) {
        if(cur >= events.size() || k == 0 || cur == -1) return 0;
        else if(dp[cur][k] == -1) {
            int next = upper_bound(events.begin() + cur + 1, events.end(), events[cur][1], [](int x, vector<int>& y) {
                return x < y[0];
            }) - events.begin();

            int c1 = events[cur][2] + helper(next, dp, events, k - 1);
            int c2 = helper(cur + 1, dp, events, k);
            dp[cur][k] = max(c1, c2);
        }
            
        return dp[cur][k];
    }
};