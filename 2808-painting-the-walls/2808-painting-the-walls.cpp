class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<int> dp(cost.size() + 1, 1e9);
        dp[0] = 0;

        for (int i = 0; i < cost.size(); ++i) {
            for (int j = cost.size(); j > 0; --j) {
                dp[j] = std::min(dp[j], dp[std::max(j - time[i] - 1, 0)] + cost[i]);
            }
        }
        
        return dp[cost.size()];
    }

};